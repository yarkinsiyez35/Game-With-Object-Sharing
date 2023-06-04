#ifndef CS_204_HW5_BOARD_H
#define CS_204_HW5_BOARD_H
#include <string>
using namespace std;

struct Node {
    string owner;
    Node* next;
    Node ()                 //default constructor
    {
        owner = "None";
        next = NULL;
    }
    Node (string o, Node * p)       // parametric constructor
    {
        owner = o;
        next = p;
    }
};

class Board
{
public:
    Board(int);             //parametric constructor
    ~Board();               //destructor
    void display() const;             //displays the content of the board
    string who_owns(Node *) const;        //returns the owner of the node
    Node * getHead() const ;               //returns the head of the board
private:
    Node * first;
};
#endif //CS_204_HW5_BOARD_H
