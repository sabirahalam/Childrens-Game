#include <iostream>
#include "Node.hpp"
#include "LinkedList.hpp"
#include <string>



int main(){

    //Create an instance of Linked List
    LinkedList game;
    std::string command;

   

while (std::cin >> command){
    //Displaying success or failure if child based on if child spawned in first quadrant
    if (command == "SPAWN"){
        double x,y;
        std::cin >> x >> y;
       
        
        bool spawnChild = game.spawnNewChild(x,y);
       

        if (spawnChild) {
            std::cout << "success" << std::endl;
        } 
        
        else {
            std::cout << "failure" << std::endl;
        }
    }

    //Displaying total number of children
    else if (command == "NUM"){
        std::cout << "number of children still playing: " << game.totalChildren() << std::endl;
    }

    
    //Displaying number of children in game after time 
    else if (command == "TIME"){
        double t;
        std::cin >> t;
        int remaining = game.moveChildrenBasedOnTime(t) ;
        std::cout << "number of children still playing: " << remaining << std::endl;
    }


    //Displaying children coordinates within distance

    else if (command == "PRT"){
        double D;
        std::cin>>D;
        game.printChildrenWithinRange(D);
    }


    //Displaying if player or wolf wins
    else if (command == "OVER"){

    bool gameOver = game.GameOver();

    if (gameOver) {
        std::cout << "the wolf wins" << std::endl;
    } 
    
    else {
        std::cout << "the players win" << std::endl;
    }

    }
    
  }
    return 0;
}