#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"

class LinkedList{

    private:
    Node *p_head; //pointer for the head node of the linked list
    int tot_Children = 0; //counter to keep track of total children in the game

    public:
        //Constructor and deconstructor declaration
        LinkedList();
        ~LinkedList();
        

        //Member functions for all commands in the game while passing appropiate parameters as per project instructions
        bool spawnNewChild(double x, double y);
        int moveChildrenBasedOnTime(double t);
        int totalChildren();
        void printChildrenWithinRange(double D);
        bool GameOver() ;

        //Getter for counter
        int getTot_Children() const;

        //Setter for counter
        int setTot_Children(int value);

    
    
};

#endif