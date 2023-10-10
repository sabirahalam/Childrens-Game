#ifndef NODE_HPP
#define NODE_HPP

//Each child is represented by a node
class Node{

    public:
    //Constructor and deconstructor declaration
    Node();
    ~Node();

    //Declaring getter/setter memeber functions 
    double getX() const;
    double getY() const;
    Node* getNext() const;
    double setX(double x1);
    double setY(double y1);
    Node* setNext(Node *next);


    private:
        //data members to store x and y coordinates of each node representing a child
        double x;
        double y;
        Node *p_next; //pointer to get next node in linked list
           
};

#endif
