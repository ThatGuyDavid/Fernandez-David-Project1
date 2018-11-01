#include "Card.h"

Card::Card(rank r, suit s, bool ifu):  Rank(r), Suit(s), IsFaceUp(ifu)
{}
 
int Card::GetValue() const
{
    //if a cards is face down, its value is 0
    int value = 0;
    if (IsFaceUp)
    {
        //value is number showing on card
        value = Rank;
        //value is 10 for face cards
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}
//Flip the Dealers face down
void Card::Flip()
{
    IsFaceUp = !(IsFaceUp);
}