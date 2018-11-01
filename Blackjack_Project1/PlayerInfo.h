#ifndef PLAYERINFO_H
#define PLAYERINFO_H
#include "Hand.h"
class PlayerInfo : public Hand
{
    friend ostream& operator<<(ostream& os, const PlayerInfo& aPlayerInfo);
     
public:
     
    PlayerInfo(const string& name = "");
     
    virtual ~PlayerInfo();
     
    //indicates whether or not generic player wants to keep hitting
    virtual bool IsHitting() const = 0;
     
    //returns whether generic player has busted - has a total greater than 21
    bool IsBusted() const;
     
    //announces that the generic player busts
    void Bust() const;
    
    //You got 21
    void TwoOne() const;;
    //See if player has 21
    bool TwentyOne() const;
     
protected:
    string Name;
};
#endif