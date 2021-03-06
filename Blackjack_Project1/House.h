#ifndef HOUSE_H
#define HOUSE_H
#include "PlayerInfo.h"

class House : public PlayerInfo
{
public:
    House(const string& name = "House");
     
    virtual ~House();
     
    //indicates whether house is hitting - will always hit on 16 or less
    virtual bool IsHitting() const;
     
    //flips over first card
    void FlipFirstCard();
};

#endif /* HOUSE_H */