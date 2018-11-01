#include "House.h"

House::House(const string& name):
PlayerInfo(name)
{}
 
House::~House()
{}
//Determine if The Dealer is going to hit
bool House::IsHitting() const
{
    return (GetTotal() <= 16);
}
//Hide The first card of the dealer
void House::FlipFirstCard()
{
    if (!(Cards.empty()))
    {
        Cards[0]->Flip();
    }
    else
    {
        cout << "No card to flip!\n";
    }
}