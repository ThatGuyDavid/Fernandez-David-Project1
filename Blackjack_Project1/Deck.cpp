#include "Deck.h"
#include "PlayerInfo.h"

Deck::Deck()
{
    Cards.reserve(52);
    Populate();
}
 
Deck::~Deck()
{}
//Populate the Deck with cards
void Deck::Populate()
{
    Clear();
    //create standard deck
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            Add(new Card(static_cast<Card::rank>(r),
                         static_cast<Card::suit>(s)));
        }
    }
}
//Random Shuffle the deck that was populated
void Deck::Shuffle()
{
    random_shuffle(Cards.begin(), Cards.end());
}
//Draw the cards to Players
void Deck::Deal(Hand& aHand)
{
    if (!Cards.empty())
    {
        aHand.Add(Cards.back());
        Cards.pop_back();
    }
    else
    {
        cout << "Out of cards. Unable to deal.";
    }
}
//After cards have been played and are lower than 25 populate again
void Deck::RePopulate()
{
    if(Cards.size() < 25)
    {
        cout<<"Re shuffling!\n";
        Populate();
        Shuffle();
    }
}
//Allow players to continue to draw until busted
void Deck::AdditionalCards(PlayerInfo& aPlayerInfo)
{
    cout << endl;
    //continue to deal a card as long as generic player isn't busted and
    //wants another hit
    while ( !(aPlayerInfo.IsBusted()) &&!(aPlayerInfo.TwentyOne()) && aPlayerInfo.IsHitting()  )
    {
        Deal(aPlayerInfo);
        cout << aPlayerInfo << endl;
        if (aPlayerInfo.TwentyOne())
        {
            aPlayerInfo.TwoOne();
        } 
        if (aPlayerInfo.IsBusted())
        {
            aPlayerInfo.Bust();
        }
    }
}
//Assist in Players to allow them to mathematically learn the best options
void Deck::BustingTip(int Total){
    if(Total == 12)
    {
        cout << "The percentage of you busting on a hit with your total is : 31%\n";
    }
    else if(Total == 13)
    {
        cout << "The percentage of you busting on a hit with your total is : 39%\n";
    }
    else if(Total == 14)
    {
        cout << "The percentage of you busting on a hit with your total is : 56%\n";
    }
    else if(Total == 15)
    {
        cout << "The percentage of you busting on a hit with your total is : 58%\n";
    }
    else if(Total == 16)
    {
        cout << "The percentage of you busting on a hit with your total is : 62%\n";
    }
    else if(Total == 17)
    {
        cout << "The percentage of you busting on a hit with your total is : 69%\n";
    }
    else if(Total == 18)
    {
        cout << "The percentage of you busting on a hit with your total is : 77%\n";
    }
    else if(Total == 19)
    {
        cout << "The percentage of you busting on a hit with your total is : 85%\n";
    }
    else if(Total == 20)
    {
        cout << "The percentage of you busting on a hit with your total is : 92%\n";
    }
    else
    {
        cout << "The percentage of you busting on a hit with your total is : 0%\n";
    }
}