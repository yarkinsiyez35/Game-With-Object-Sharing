#include <string>
#include <iostream>
#include "Player.h"
using namespace std;


Player::Player(Board & board, string name, int balance): sharedBoard(board), playerName(name), playerBalance(balance)
{
    currentPosition = board.getHead();          //starts at the first slot
}

int Player::move(int steps)                     //moves the player steps many times
{
    bool passed = false;                    //creates a bool value that will update if player moves over the first node
    Node * beginningNode = sharedBoard.getHead();                //stores the first node
    for (int i = 0; i< steps; i++)                      //traverses steps many times
    {
        currentPosition = currentPosition->next;
        if (currentPosition == beginningNode)               //if the currentPosition becomes the first node
        {
            passed = true;                                  //updates the parameter
        }
    }
    if (passed)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Node* Player::where_am_I()               //returns the current position of the player
{
    return currentPosition;
}

void Player::pay_to_player(Player &otherPlayer, int toBePaid)           //gives toBePaid money from the player to the otherPlayer
{
    playerBalance -= toBePaid;                          //withdraws toBePaid much money from the player
    otherPlayer.playerBalance += toBePaid;              //adds toBePaid much money to the other player
}

int Player::get_balance()        const           //returns the balance of the player
{
    return playerBalance;
}

void Player::deposit_money(int toBeDeposited)                //adds toBeDeposited much money to the player
{
    playerBalance += toBeDeposited;
}

void Player::buy_slot(int price)                        //buys a slot
{
    currentPosition->owner = playerName;            //assigns playerName to the current slot
    playerBalance -= price;                         //withdraws price much money from the player
}

bool Player::is_bankrupt()      const            //returns true if player has <0 money
{
    return playerBalance <0;
}

void Player::display()  const
{
    Node * head = sharedBoard.getHead();         //head stores the first node
    Node * temp = head;                          //a temp node to find the player's current node
    int count = 0;                                      //player is at the first node as of now
    while (temp != currentPosition)
    {
        temp = temp->next;
        count++;                                    //increments the count until player's node is found
    }

    for (int i = 0; i< count; i++)                  //gives count many 6 spaces to reach the player's node
    {
        cout << "      ";
    }
    cout << playerName << " " << playerBalance << endl;
}



