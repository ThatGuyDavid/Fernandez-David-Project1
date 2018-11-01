#include "PlayerInfo.h"

PlayerInfo::PlayerInfo(const string& name):
Name(name)
{}
 
PlayerInfo::~PlayerInfo()
{}
//Bool of if the player's total has surpassed 21
bool PlayerInfo::IsBusted() const
{
    return (GetTotal() > 21);
}
 //Players total has surpassed 21
void PlayerInfo::Bust() const
{
    cout << Name << " busts.\n";
}
//Player's total is 21
void PlayerInfo::TwoOne() const
{
    cout << Name << " Got 21.\n";
}
//Determine if player's total is 21
bool PlayerInfo::TwentyOne() const
{
    return (GetTotal() == 21);
}