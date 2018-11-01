#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card
{
public:
    //The Ranks of the cards Face value
    enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING};
    //The Suit given to the card
    enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};
     
    //overloading << operator so can send Card object to standard output
    friend ostream& operator<<(ostream& os, const Card& aCard);
     
    Card(rank r = ACE, suit s = SPADES, bool ifu = true);
     
    //returns the value of a card, 1 - 11
    int GetValue() const;
     
    //flips a card; if face up, becomes face down and vice versa
    void Flip();
     
private:
    //Cards Given Rank
    rank Rank;
    //Cards Given Suit
    suit Suit;
    //Cards is being shown or isn't
    bool IsFaceUp;
};

#endif /* CARD_H */