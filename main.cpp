#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Item.h"
#include "Player.h"
#include "Storage.h"
#include "Game.h"

using namespace std;

#ifdef _WIN32
const std::string os_name = "Windows";
#elif __APPLE__
const std::string os_name = "Mac OS";
#elif __linux__
const std::string os_name = "Linux";
#else
const std::string os_name = "Unknown";
#endif

int main()
{
    Player P;
    Game game(P);
    //P.showEq();
    while (true){
		if (os_name == "Windows") system("cls");
		else system("clear"); 
		P.DoIHaveSomeFreeSpace();
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
