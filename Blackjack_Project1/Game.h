#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Deck.h"
#include "House.h"
#include "Rules.h"

class Game
{
public:
    Game(const vector<string>& names);
     
    ~Game();
     
    //plays the game of blackjack
    void Play();
     
private:
    //Deck to create the 52 cards in the game itself
    Deck Deck;
    //House to give the "Dealer" his hand
    House House;
    //Give the Player his money total and his hand
    vector<Player> Players;
};


#endif /* GAME_H */