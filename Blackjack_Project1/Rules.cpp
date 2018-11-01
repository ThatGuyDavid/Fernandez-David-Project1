#include "Rules.h"
#include <iostream>
using namespace std;
    Rules::Rules()
    {};               
    Rules::~Rules()
    {};       
    //Present Menu for sections in rules
    void Rules::RulesMenu()
    {
        int choice;
        cout << "\t\tRules of Blackjack\n\n"
                "\nChoice 1: Do you wish to learn the rules of the game?"
                "\nChoice 2: What does 'Hit' mean?"
                "\nChoice 3: What does 'Stand' mean"
                "\nChoice 4: Ready To Start a Game?" <<endl; 
        cin >> choice;
        cout << "\n";
        //Validate int
        if (cin.fail())
        {
            while(!(cin >> choice)) {
                cin.clear();
                cin.ignore(1000, '\n');
                system("Clear");
                cout << "Sorry That wasn't a valid choice. Please try again. \n\n";
                RulesMenu();
            }
        }
        //only let through 1-4
        if(choice>=1 && choice <= 4)
        {
            switch(choice)
            {
                case 1: Rule();
                case 2: Hit();
                case 3: Stand();
                case 4: return;
            }
        }
        //Clear console then repeat informing of error in input
        else
        {
            system("clear");
            cout << "Sorry That wasn't a valid choice. Please try again. \n\n";
            RulesMenu();
        }
        system("clear");
    }
    //Explain the rules of the game
    void Rules::Rule()
    {
        cout << "Blackjack may be played with one to eight decks of 52-card decks. Aces may be counted "
                "\nas 1 or 11 points, 2 to 9 according to pip value, and tens and face cards count as ten "
                "\npoints.The value of a hand is the sum of the point values of the individual cards. "
                "\nExcept, a blackjack is the highest hand consisting of an ace and any 10-point card, "
                "\nand it outranks all other 21-point hands. After the players have bet, the dealer will "
                "\ngive two cards to each player and two cards to himself. One of the dealer cards is dealt "
                "\nface up. The facedown card is called the hole card. If the dealer has a blackjack, then all "
                "\nwagers will lose, unless the player also has a blackjack, which will result in a push. "
                "\nAfter each player has had his turn, the dealer will turn over his hole card. If the dealer "
                "\nhas 16 or less, then he will draw another card. A special situation is when the dealer has "
                "\nan ace and any number of cards totaling six points (known as a 'soft 17'). At some tables, "
                "\nthe dealer will also hit a soft 17. If the dealer goes over 21 points, then any player "
                "\nwho didn't already bust will win. If the dealer does not bust, then the higher point "
                "\n\t\ttotal between the player and dealer will win.\n\n";
        RulesMenu();
    }
    //What hit is
    void Rules::Hit()
    {
        cout << "Player draws another card (and more if he wishes). If this card causes the player's total "
                "\n\t\tpoints to exceed 21 (known as 'breaking' or 'busting') then he loses.\n\n";
        RulesMenu();
    }
    //What stand means
    void Rules::Stand()
    {
        cout << "When the total value of your hand is 21 or lower, and can choose to stand and not "
                "\n\t\tto risk the chance of your hand(s) exceeding 21 in total value.\n\n";
        RulesMenu();
    }