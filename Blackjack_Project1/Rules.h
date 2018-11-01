#ifndef RULES_H
#define RULES_H
using namespace std;
class Rules
{
    public:     
    Rules();
    ~Rules(); 
    
    //Presents the menu selection of Rules to the user
    void RulesMenu();        
    
    //Introduces the rules to the player
    void Rule();     
    
    //Presents meaning of a 'Hit' in Blackjack
    void Hit();          
    
    //Presents meaning of 'Stand' in Blackjack
    void Stand();        
    
};

#endif /* RULES_H */