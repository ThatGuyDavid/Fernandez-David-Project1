#include "Game.h"

Game::Game(const vector<string>& names)
{
    //create a vector of players from a vector of names
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
    {
        Players.push_back(Player(*pName));
    }
     
    //seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    Deck.Populate();
    Deck.Shuffle();
}
 
Game::~Game()
{}
//Game Function runs the game
void Game::Play()
{
    system("clear");
    Deck.RePopulate();
    vector<Player>::iterator pPlayer;
    //Asks for an initial be. If they are betting
    for (pPlayer = Players.begin();
            pPlayer != Players.end(); ++pPlayer)
    {
        pPlayer->Bet();
    }
    
    //deal initial 2 cards to everyone 
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = Players.begin(); 
                pPlayer != Players.end(); ++pPlayer)
        {
            Deck.Deal(*pPlayer);
        }
        Deck.Deal(House);
    }
     
    //hide house's first card
    House.FlipFirstCard();
     
    //display everyone's hand
    for (pPlayer = Players.begin(); 
            pPlayer != Players.end(); ++pPlayer)
    {
        cout << *pPlayer<< endl;
    }
    cout << House << endl;
    //deal additional cards to players
    for (pPlayer = Players.begin();
            pPlayer != Players.end(); ++pPlayer)
        {
            Deck.BustingTip(pPlayer->GetTotal());
            Deck.AdditionalCards(*pPlayer);
        }
    //reveal house's first card
    House.FlipFirstCard();
    cout << endl << House;
     
    //deal additional cards to house
    Deck.AdditionalCards(House);
     
    if (House.IsBusted())
    {
        //everyone still playing wins
        for (pPlayer = Players.begin(); 
                pPlayer != Players.end(); ++pPlayer)
        {
            if ( !(pPlayer->IsBusted()) )
            {
                pPlayer->Win();
            }
        }
    }
    else
    {
        //compare each player still playing to house
        for (pPlayer = Players.begin(); 
                pPlayer != Players.end(); ++pPlayer)
        {
            if(pPlayer->IsBusted())
            {
                pPlayer->Lose();
            }
            if ( !(pPlayer->IsBusted()) )
            {
                if (pPlayer->GetTotal() > House.GetTotal())
                {
                    pPlayer->Win();
                }
                else if (pPlayer->GetTotal() < House.GetTotal())
                {
                    pPlayer->Lose();
                }
                else
                {
                    pPlayer->Push();
                }
            }
        }
         
    }
     
    //remove everyone's cards
    for (pPlayer = Players.begin(); 
            pPlayer != Players.end(); ++pPlayer)
    {
        pPlayer->Clear();
    }
    House.Clear();
}