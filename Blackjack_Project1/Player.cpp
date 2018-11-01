#include "Player.h"

Player::Player(const string& name, int money):
PlayerInfo(name)
{}
 
Player::~Player()
{}
//Create the bet if player wishes and calculate the bet amount 
void Player::Bet()
{
    cout << Name<<"($"<<Money<<") , do you want to Bet (Y/N): ";
    string response;
    cin >> response;  
    if (cin.fail() || response.size() > 1)
    {
            cin.clear();
            cin.ignore(1000, '\n');
            system("Clear");
            cout << "Sorry That wasn't a valid choice. Please try again. \n\n";
            Bet();
    }
    if(response[0] == 'y' || response[0] == 'Y')
    {
        cout<<"how much would you like to Bet?";
        cin>>BetT;
        if(BetT > Money || BetT < 0)
        {
            cout << "Sorry that was not a valid Bet amount please try again\n";
            Bet();
        }
        
    }
    else if(response[0] == 'n' || response[0] == 'N')
    {
        return;
    }
}
//Calculate the total of the money after loss a player will get and their new total
void Player::Loses()
{
    Money -=  BetT;
    cout << "Your Balance Total Is Now: " << Money << endl;
}
//Calculate the total of the money after winning a player will get and their new total
void Player::Winnings()
{
    Money += BetT;
    cout << "Your Balance Total Is Now: " << Money << endl;
}
//Logic of whether the player decides to hit or not
bool Player::IsHitting() const
{
    cout << Name << ", do you want a hit? (Y/N): ";
    string response;
    cin >> response;
    if (cin.fail() || response.size() > 1)
    {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Sorry That wasn't a valid choice. Please try again. \n\n";
            IsHitting();
    }
    if(response[0] == 'y' || response[0] == 'Y')
    {
        return (response[0] == 'y' || response[0] == 'Y');
    }
    else if (response[0] == 'n' || response[0] == 'N')
    {
        return false;
    }
    
}
//Player is told he won
void Player::Win()
{
    cout << Name <<  " wins.\n";
    Winnings();
}
//Player is told he Lost
void Player::Lose()
{
    cout << Name <<  " loses.\n";
    Loses();
}
 //Dealer and Player push
void Player::Push() const
{
    cout << Name <<  " pushes.\n";
}
//Not implemented yet
void Player::DoubleDown(){
    cout << "Would you like to double down? (Y/N)\n";
    char response;
    cin >> response;
    if(response == 'y' || response == 'Y')
    {
        BetT *= 2;
        Double = true;
    }
    else if (response == 'n' || response == 'N')
    {
        Double = false;
    }
    else{
        cout << "Sorry that was not a valid response please try again\n";
        DoubleDown();
    }
}