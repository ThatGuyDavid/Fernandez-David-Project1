#ifndef Hand_H
#define Hand_H
#include <vector>
#include "Card.h"

class Hand
{
public:
    Hand();
     
    virtual ~Hand();
     
    //adds a card to the hand
    void Add(Card* pCard);
     
    //clears hand of all cards
    void Clear();
     
    //gets hand total value, intelligently treats aces as 1 or 11
    int GetTotal() const;
     
protected:
    //Used to create the cards for the hand(Hitting and adding the face value)
    vector<Card*> Cards;
};

#endif /* HAND_H */