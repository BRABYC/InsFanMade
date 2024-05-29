#include <iostream>
#include <string>
#include <iomanip>
#include <map> 
#include <cstdlib>
#include "Item.h"
#include "Player.h"
#include "Storage.h"
#include "Game.h"
#include "Windows.h"
#include <thread>
#include <chrono>


using namespace std;

#ifdef _WIN32
const int os_name = 1;
#elif __APPLE__
const int os_name = 0;
#elif __linux__
const int os_name = 0;
#else
const int os_name = -1;
#endif

int main()
{
	srand(time(NULL));
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);
	bool gameLoop = true;
    bool basic_setup = true;
    Player P;
    Game game(P, gameLoop, basic_setup, os_name);

    // loading screen --------------------------------
    cout << "please unequip your items before exit the game, i didn't setup player stats saving yet" << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    game.StartScreen();
    this_thread::sleep_for(chrono::milliseconds(500));
    game.loadingAnimation(40);
    // -----------------------------------------------

    P.loadInventory();

    while (gameLoop){
		if (basic_setup) {
            if (os_name == 1) system("cls");
            else system("clear");
            game.DisplayInvertory();
        }
        else {
            game.Lore();
        }
        game.input();
    }

    P.saveInventory();


	return 0;
}
