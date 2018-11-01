#ifndef PLAYER_H
#define PLAYER_H
#include <string.h>
#include "PlayerInfo.h"

class Player : public PlayerInfo
{
public:
    Player(const string& name = "", int money = 100);
     
    virtual ~Player();
     
    //returns whether or not the player wants another hit
    virtual bool IsHitting() const;
    //Calculates the bet amount made and makes sure its within the players limit
    void Bet();
    //Calculates the new amount total of the player after losing
    void Loses();
    //Calculates the new amount total of the player after winning
    void Winnings();
     
    //announces that the player wins
    void Win();
     
    //announces that the player loses
    void Lose();
     
    //announces that the player pushes
    void Push() const;
    
    //Ask the player if he would like to double down
    void DoubleDown();
     
public:
    //starting amount of money
    int Money = 100;
    //The int for the BetTotal
    int BetT;
    //Whether you want to double or not
    bool Double;
};

#endif /* PLAYER_H */