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
	srand(time(NULL));
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);
    Player P;
    Game game(P);
    //P.showEq();
    game.StartScreen();
    this_thread::sleep_for(chrono::seconds(3));

    while (true){
		if (os_name == "Windows") system("cls");
        else system("clear"); 
        game.showUI();
        game.input();
    }


    return 0;
}
