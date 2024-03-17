#include <iostream>
#include <string>
#include "Item.h"
#include "Player.h"

using namespace std;


int main()
{
    Player P;
    //P.showEq();
    P.displayPlayerStats();
    P.setMainWeapon(1, 2);
    //P.setMainArmor(2, 1);
    //P.setMainWeapon(2, 0);
    //P.setMainArmor(2, 3);
    for(int i = 0; i < 5; i++){
        P.moveInEquipment();
        P.displayPlayerStats();
    }
    return 0;
}
