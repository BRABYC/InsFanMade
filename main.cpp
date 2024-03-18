#include <iostream>
#include <string>
#include <iomanip>
#include "Item.h"
#include "Player.h"
#include "Storage.h"
#include "Game.h"

using namespace std;


int main()
{
    Player P;
    Game game(P);
    //P.showEq();
    for(int i = 0; i < 10;i++){
        game.showUI();
        game.input();
    }
    //P.setMainWeapon(1, 2);
    //P.setMainArmor(2, 1);
    //P.setMainWeapon(2, 0);
    //P.setMainArmor(2, 3);
    //for(int i = 0; i < 10; i++){
      //  P.moveInEquipment();
      // P.deleteItem();
        //for(int i = 0; i < 5;i++){
            //P.displayOneRow(i);
        //P.displayPlayerStats();
       //}
    //}

    return 0;
}
