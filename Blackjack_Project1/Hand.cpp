#include "Hand.h"

Hand::Hand()
{
    Cards.reserve(7);
}
 
Hand::~Hand()
{
    Clear();
}
//add a card to the Hand
void Hand::Add(Card* pCard)
{
    Cards.push_back(pCard);
}
//Clear the Hand
void Hand::Clear()
{
    //iterate through vector, freeing all memory on the heap
    vector<Card*>::iterator iter = Cards.begin();
    for (iter = Cards.begin(); iter != Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    //clear vector of pointers
    Cards.clear();
}
//Return the total of all cards in the Hand
int Hand::GetTotal() const
{
    //if no cards in hand, return 0
    if (Cards.empty())
    {
        return 0;
    }
     
    //if a first card has value of 0, then card is face down; return 0
    if (Cards[0]->GetValue() == 0)
    {
        return 0;
    }
     
    //add up card values, treat each Ace as 1
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = Cards.begin(); iter != Cards.end(); ++iter)
    {
        total += (*iter)->GetValue();
    }
     
    //determine if hand contains an Ace
    bool containsAce = false;
    for (iter = Cards.begin(); iter != Cards.end(); ++iter)
    {
        if ((*iter)->GetValue() == Card::ACE)
        {
            containsAce = true;
        }
    }
     
    //if hand contains Ace and total is low enough, treat Ace as 11
    if (containsAce && total <= 11)
    {
        //add only 10 since we've already added 1 for the Ace
        total += 10;
    }
     
    return total;
}