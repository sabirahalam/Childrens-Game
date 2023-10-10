#include <iostream>
#include "Node.hpp"


//Defining constructor
Node::Node(){
    
    //next pointer not initially connected to any nodes
    p_next = nullptr;
}

//Define Deconstructor
Node::~Node(){}


 //Defining (getter methods) for private data members
double Node::getX() const{
    return x;
}
double Node::getY() const{
    return y;
}
Node* Node::getNext() const {
    return p_next;
}


//setter methods
double Node::setX(double x1){
    x = x1;
    return x;
}
double Node::setY(double y1){
    y = y1;
    return y;
}
Node* Node::setNext(Node *next){
    p_next = next;
    return p_next;
}
