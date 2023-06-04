#ifndef CS_204_HW5_PLAYER_H
#define CS_204_HW5_PLAYER_H

#endif //CS_204_HW5_PLAYER_H
#include "Board.h"
#include <string>
using namespace std;

class Player{
public:
    Player(Board&, string, int);            //parametric constructor
    int move(int);                          //moves player parameter many steps, returns 1 if a lap is completed, returns 0 else
    Node* where_am_I();              //returns the position of the player on the board
    void pay_to_player(Player &, int);      //adds parameter money to other player,
    int get_balance() const ;                      //returns player's balance
    void deposit_money(int);                 //adds parameter money to the player
    void buy_slot(int);                     //assigns player's name to the slot, withdraws parameter money from the player
    bool is_bankrupt() const;                     //returns true if bankrupt, returns false else
    void display() const ;                         //displays the name and the balance of the player
private:
string playerName;
int playerBalance;
Node * currentPosition;
Board & sharedBoard;
};