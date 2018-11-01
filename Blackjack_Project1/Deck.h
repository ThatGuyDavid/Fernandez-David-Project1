#ifndef DECK_H
#define DECK_H
#include <algorithm>
#include "Hand.h"
#include "PlayerInfo.h"

class Deck : public Hand
{
public:
    Deck();
     
    virtual ~Deck();
     
    //create a standard deck of 52 cards
    void Populate();
     
    //shuffle cards
    void Shuffle();
     
    //deal one card to a hand
    void Deal(Hand& aHand);
     
    //give additional cards to a generic player
    void AdditionalCards(PlayerInfo& aPlayerInfo);
    
    //Provides the Player with a percentage of him busting on the hitting
    void BustingTip(int);
    
    //Resets the deck for another game with 52 cards
    void RePopulate();
    private:
        Hand hand;
};


#endif /* DECK_H */