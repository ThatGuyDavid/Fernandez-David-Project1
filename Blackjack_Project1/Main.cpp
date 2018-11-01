#include "Game.h"
#include <stdlib.h>

ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const PlayerInfo& aPlayerInfo);
void start();
//MainMenu of the Blackjack game
int main()
{
    int choice;
    Rules Rule;
    cout << "\t\tWelcome to Blackjack!\n\n";
    cout << "Choice 1: Learn the Game of BlackJack?"
            "\nChoice 2: Start a Game"
            "\nChoice 3: Quit The Game\n";
    cin >> choice;
    cout << "\n";
    //Validate int choice to be int
    if (cin.fail())
    {
        while(!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            system("Clear");
            cout << "Sorry That wasn't a valid choice. Please try again. \n\n";
            main();
        }
    }
    if(choice <=3 && choice >=1)
    {
        switch(choice)
        {
                case 1: system("clear");Rule.RulesMenu(); main();
                case 2: system("clear");start();main();
                case 3: exit(0);
        }
    }
    else{
        system("clear");
        cout << "Sorry That wasn't a valid choice. Please try again. \n\n";
        main();
    }
   
    return 0;
}
 
//overloads << operator so Card object can be sent to cout
ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};
     
    if (aCard.IsFaceUp)
    {
        os << RANKS[aCard.Rank] << SUITS[aCard.Suit];
    }
    else
    {
        os << "XX";
    }
    return os;
}

//overloads << operator so a PlayerInfo object can be sent to cout
ostream& operator<<(ostream& os, const PlayerInfo& aPlayerInfo)
{
    os << aPlayerInfo.Name << ":\t";
    vector<Card*>::const_iterator pCard;
    if (!aPlayerInfo.Cards.empty())
    {
        for (pCard = aPlayerInfo.Cards.begin();
             pCard != aPlayerInfo.Cards.end();
             ++pCard)
        {
            os << *(*pCard) << "\t";
        }   
        if (aPlayerInfo.GetTotal() != 0)
        {
            cout << "(" << aPlayerInfo.GetTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }
     
    return os;
}
void start()
{
    //Initialize player size to 0
    int numPlayers = 0;
    //Amount of players playing
    while (numPlayers < 1 || numPlayers > 7)
    {
        system("Clear");
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
        //Only allow int and numbers 1-7 players
        if (cin.fail())
    {
        while(!(cin >> numPlayers)) {
            cin.clear();
            cin.ignore(1000, '\n');
            system("Clear");
            cout << "Sorry That wasn't a valid choice. Please try again. \n\n";
            start();
        }
    }
    }
    //Capturing the names
    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;
     
    //the game loop
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        system("clear");
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
        if(again == 'n' || again == 'N')
        {
            main();
        }
    }
}