#include <iostream>
#include <string>
#include "Item.h"
#include "Player.h"
#include "Game.h"

using namespace std;


int main()
{
    Player P;
    Game Game(P);
    //P.showEq();
    P.displayPlayerStats();
    //P.setMainWeapon(1, 2);
    //P.setMainArmor(2, 1);
    //P.setMainWeapon(2, 0);
    //P.setMainArmor(2, 3);
    while(true){
       Game.PlayerInput();
       P.displayPlayerStats();
    }
    return 0;
}
