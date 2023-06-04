#include <iostream>
#include <string>
#include "Board.h"

Board::Board(int n)             //parametric constructor
{
    Node * h = new Node();      //creates a new Node
    first = h;
    for (int i = 0; i< n-1; i++)                //creates n-1 many nodes
    {
        Node * temp = new Node();
        h->next = temp;
        h = temp;
    }
    h->next = first;                //connects the tail with head
}

Board::~Board()                     //destructor
{
    Node * temp = first->next;          //starts deleting from the second node
    while (temp != first)               //deletes every node except the first one
    {
        Node * toBeDeleted = temp;      //creates a node to delete
        temp = temp->next;              //goes to the next node
        delete toBeDeleted;
        toBeDeleted = NULL;             //good practice
    }
    delete first;                       //deletes first node
    first = NULL;                       //good practice
}


void Board::display() const          //displays the content of the board
{
    /*printing the first line*/
    string s;                   //will store the board content, this is useful for printing the second and third lines
    s = first->owner;
    if (first->owner != "None")
    {
        s+= " ";                //adds one space because of the printing format
    }
    Node * temp = first->next;
    int count = 1;                  //stores how many slots there are
    while (temp != first)                       //while there are other elements
    {
        s+= "->" + temp->owner;             //adds to the string
        if (temp->owner != "None")
        {
            s += " ";                       //adds one space because of the printing format
        }
        temp = temp->next;                  //goes to the next
        count++;                        //increments the count
    }
    cout << s << endl;                  //prints the first line
    /*printing the second line*/
    cout << "^";
    int stringLength = s.length();
    for (int i = 0; i< stringLength-2; i++)         //adds required amount of space
    {
        cout <<" ";
    }
    cout << "|" << endl;
    /*printing the third line*/
    cout << "|----";
    for (int i = 0; i< count-2; i++)                    //prints count-2 many normal arrows
    {
        cout << "<-----";
    }
    cout << "<---v" << endl;
}

string Board::who_owns(Node * location)       const              //returns the location owner
{
    return location->owner;
}

Node * Board::getHead()  const            //returns the head
{
    return first;
}






