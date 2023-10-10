#include <iostream>
#include <cmath>
#include "LinkedList.hpp"


        
//Managing list of children in the game


//Defining Constructor
LinkedList::LinkedList(){
    p_head = nullptr; //head pointer not initially connected to anything
    tot_Children = 0;
}


//Defining Deconstructor (deallocating memory)
LinkedList::~LinkedList(){

    //Initialize current pointer to head/beginning of linked list
    Node* current = p_head;

    //traverse through linked list as long as current points to valid node
    while (current != nullptr){

        //get the next node by calling appropiate getter member function 
        Node* next = current->getNext(); //also created next pointer to store next value before deleting current node
        delete current;
        current = next;
    }
}

//Getter function
int LinkedList::getTot_Children() const{
    return tot_Children;
    }


//Setter function (gpt)
int LinkedList::setTot_Children(int value){
    tot_Children = value;
    return tot_Children;
}

//MEMBER FUNCTIONS



/*
    CITATION:

    I was recieving an error accessing the p_head private data member for my 
    spawnNewChild function, advised by chat.openai.com with the prompt: "My code is not
    allowing me to access the p_head variable, how can I fix this error?"

    The AI tool advised me to make it a public function so I can add nodes without
    having to access private data members and still maintaining encapsulation.
    This was a great appraoch and applicable to my other functions as well.
*/


//Spawn new child to play the game at coordinates (x,y) if their position lies within first quadrant 
bool LinkedList::spawnNewChild(double x, double y){
    
        //if their position is in the first quadrant, add to linked list
    if (x>0 && y>0){
       
        //create new node object 
        Node *spawnNewChild = new Node();
        spawnNewChild -> setX(x);
        spawnNewChild -> setY(y);
        spawnNewChild->setNext(p_head); //setting current head pointer to new child node 
        p_head = spawnNewChild; //adding child to beginning of list
       
    
        //Keep track of children being added
        tot_Children++;
        return true;
    }
    return false;
}


//Moving children certain amount of units based on non-negative and negative time
int LinkedList::moveChildrenBasedOnTime(double t){
    //Begin at the head of the list
    Node* current = p_head;
    
    //to track previous node
    Node* previous = nullptr;

    //Transverse through linked list as long as valid node
    while(current != nullptr){


        //if the time in non-negative
        if(t>0){

            /*
                CITATION:

                Not having used math library in a while, advised by chat.openai.com with the prompt: 
                "can you guide me towards writing the following mathematical equation: 𝑡 cos(𝑎𝑡𝑎𝑛2(𝑦, 𝑥)) ?"

                The AI tool helped me format the mathematical formula to calculate the childrens movement
                and helped me derive the remaining equations required for this project
            */
           
            double deltaX = t * cos(atan2(current->getY(), current->getX()));
            double deltaY = t * sin(atan2(current->getY(), current->getX()));

            //Update the childs x and y positions
            current->setX(current->getX() - deltaX);
            current->setY(current->getY() - deltaY);


            //Check if child is out of first quadrant
            if(current->getX() < 0 || current->getY() < 0){

                //to delete the child node
                Node* deleteNode = current;

                //If the child we are deleting is at the beginning of the list
                if(previous == nullptr){

                    //set head of the list to the node after current node
                    p_head = current->getNext();
                }
                else{
                    //link previous node to the node after current node
                    previous->setNext(current->getNext());
                }

                current = current ->getNext();//update current after deletion
                delete deleteNode;
                tot_Children--;
                continue;
            }
        }

        //else if time is negative
        else if (t<0){

            
            double distance = sqrt(pow(current->getX(), 2) + pow(current->getY(), 2));

           
            if(distance <1){
                Node* deleteNode = current;


                //If the child we are deleting is at the beginning of the list
                if(previous == nullptr){
                    p_head = current->getNext();
                }
                else{
                    previous->setNext(current->getNext());
                }

                current = current ->getNext(); //update current after deletion
                delete deleteNode;
                tot_Children--;
                continue;
            }
        }
                previous = current;
                current = current->getNext();
            
    
    }
    return totalChildren();
}

//Output number of children still playing in the game
int LinkedList::totalChildren(){
    return tot_Children;
}


//Output the coordinates of all children within a distance strictly less than D from the wolf
void LinkedList::printChildrenWithinRange(double D){
    //Initialize current pointer to head/beginning of linked list
    Node* current = p_head; 
    bool childDetectWithinRange = false; //new child detector (starts by assuming no children within range)

    //Transverse through the list as long as valid node
    while (current != nullptr){

        //get x and y coordinates from each note
        double x = current->getX();
        double y = current->getY();

        //Calculating distance of children from wolf (@ origin) 
        double distanceFormula = std::sqrt(x*x + y*y);


        //to check if distance of child is less than specified distance D
        if (distanceFormula < D){

            //detect child and print childs coordinates
            childDetectWithinRange = true;
            std::cout<< x << " " << y << " ";
        }

        //Keep moving along to next child
        current = current->getNext();   
    }
    
 
        if(!childDetectWithinRange){
            std::cout << "no children within distance" << std::endl;
        }
        else{
            std::cout << std::endl;
        }
}


//Check if game is over 
bool LinkedList::GameOver() {
    if (tot_Children <= 0){

        return true;
    }
    else{
        return false;
    }
}


