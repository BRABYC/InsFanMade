#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Shop.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <thread>

class Game {
private:
    Player player;
    bool shop_mode;
    bool show_help;
    bool& gameLoop;
    Shop* shop;
    vector<string> console;

public:
    Game(const Player& player, bool& gameLoop) : player(player), gameLoop(gameLoop) {
        shop_mode = false;
		show_help = false;
        shop = new Shop();
        console.resize(5);
		gameLoop = true;
    }

    void HelpMEPLS() {
        show_help = !show_help; 
    }

    void ShowConsole() {
        cout << "+====================================================================================================================================+" << endl;
        if (console.size() > 5) {
            console.erase(console.begin());
        }
        for (int i = 0; i < console.size(); i++) {
            cout << "| ";
            cout << left << setw(130) << console[i];
            cout << " |" << endl;
        }
        cout << "+====================================================================================================================================+" << endl;
    }

    void StartScreen() {
        SetConsoleOutputCP(CP_UTF8);
        
        cout << "                            ░░▓▓░░" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                            ▒▒▓▓▓▓▓▓▓▓██▒▒          ██▓▓████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                            ▒▒██▓▓▓▓▓▓▓▓████████▓▓▓▓▓▓▓▓██████████▒▒░░" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                            ▒▒░░▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓██████████▓▓▓▓▓▓        ▒▒████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                            ▒▒░░▓▓▓▓▒▒▒▒▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████▓▓▓▓░░░░" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                            ▒▒░░▒▒▒▒▒▒▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓██▓▓▓▓▓▓▓▓░░░░░░" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                            ▒▒▒▒▓▓▒▒██▒▒▒▒▓▓▒▒████▓▓▓▓▓▓▓▓▓▓▓▓████▓▓██▓▓▓▓▒▒░░░░░░░░" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                              ░░████▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓░░▒▒██▓▓▒▒░░░░░░▒▒" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                            ░░██████▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓██▓▓████▒▒▓▓▓▓░░░░░░░░▒▒" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                          ░░▓▓██▓▓▓▓▓▓██▓▓▓▓██▓▓▓▓▓▓▓▓████████▓▓██████▓▓▓▓██▒▒░░░░░░" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                          ░░██████▓▓██▓▓██████▓▓▓▓▓▓████████▓▓██▓▓████▓▓▓▓████░░░░██" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                          ████▓▓██▓▓██▒▒██████▓▓▓▓▓▓████████▓▓██▓▓████▓▓▓▓████▒▒░░▓▓" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                        ▓▓██████████▓▓░░████████▓▓████▓▓████████▓▓████▓▓▓▓████▓▓██" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                        ▓▓██████████▒▒░░████████▓▓████▓▓██████████████▓▓▓▓████▓▓██" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                        ▓▓██████████░░░░████████▓▓████▓▓████████████████▓▓████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                        ▓▓██████████░░████████████████  ██████████████▓▓▓▓████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                        ▓▓██████████░░░░██▓▓▓▓▓▓██████░░██████████████████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                        ▓▓██████▓▓██░░░░▓▓▓▓▓▓▓▓▓▓▓▓██░░████▓▓████████████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                        ▓▓██████▓▓██▒▒██▓▓▓▓██████▓▓▒▒░░▒▒▓▓████████▒▒████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                        ▓▓████████▒▒████▓▓░░░░░░░░░░░░████████████████████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                        ██████████  ▓▓▓▓▓▓░░      ░░░░██  ▓▓▓▓██▓▓██▓▓██████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                        ████████░░▒▒▓▓▓▓▓▓        ░░░░██░░▓▓▓▓▓▓▓▓▓▓████████████░░" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                        ▓▓██████░░▒▒▓▓▓▓▓▓    ░░░░░░░░░░▒▒░░▓▓▓▓██▒▒████████████▓▓" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                          ████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒████████████                                  Yes it's an anime girl" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                          ▓▓██████▒▒░░░░░░░░░░  ░░  ░░░░░░░░░░░░░░██████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                          ▒▒██████▒▒░░░░░░░░▒▒  ░░░░░░░░░░░░░░░░░░██████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                            ████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓██████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                          ▒▒████████▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓██████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                          ██████████▒▒  ░░      ██░░░░░░░░░░░░░░████████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "                        ▓▓██  ██████  ██▒▒      ░░░░░░░░░░░░▓▓▓▓▓▓██████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "  ░░▓▓                  ██    ██████░░██████▓▓  ░░  ░░░░▓▓▒▒▓▓▒▒██████████████▒▒" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "  ██░░▓▓              ▒▒░░    ░░██▒▒░░██████████░░░░░░██▒▒░░████████████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "  ▓▓▒▒░░▓▓          ▓▓▒▒        ██▒▒▒▒██████████████████████████████████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "      ▓▓░░▒▒░░  ▒▒████░░      ░░██▓▓██▓▓▓▓▓▓▓▓▓▓████▒▒██████████▒▒▓▓████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "        ░░▒▒██████░░░░░░    ▒▒▓▓██▒▒░░░░░░░░    ░░▒▒▓▓▓▓▒▒▒▒░░░░▒▒██████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "          ██▒▒▓▓░░▒▒░░░░  ██████░░██  ░░░░    ██░░░░██▓▓▒▒░░░░▒▒▒▒▒▒▒▒▒▒▓▓██████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "        ▒▒▓▓▓▓░░██▒▒░░  ████████▓▓▒▒▒▒  ░░  ▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓████░░" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "      ░░░░░░░░░░▓▓██░░  ▓▓████████▒▒░░▒▒    ██  ░░░░░░░░▒▒░░░░░░      ░░░░░░▒▒████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "      ▓▓▒▒▒▒▒▒░░▓▓████▓▓████████████▓▓▒▒    ▒▒  ░░░░░░▒▒░░░░░░░░      ░░░░░░░░▓▓██" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "      ▒▒░░░░░░░░▒▒██▒▒██████████████  ▒▒▒▒░░▒▒  ░░░░▒▒  ░░            ▒▒▒▒▒▒░░▒▒██▒▒" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "    ▒▒░░░░▒▒▒▒▓▓░░████████████████████▒▒▒▒▒▒▒▒  ▓▓░░  ░░▒▒  ▒▒▒▒████▒▒▒▒▒▒▒▒▓▓██████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "    ▒▒▒▒░░░░░░▒▒░░██████████████████████▒▒████░░▓▓██▓▓██░░██████▒▒██████████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << "      ░░██░░░░░░▒▒▓▓████████████████████▓▓██████████████████░░░░▓▓██████████████████" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));

        
    }
    void loadingAnimation() {
        int width = 50; // Width of the progress bar
        for (int i = 0; i <= width; ++i) {
            cout << "                       [";
            for (int j = 0; j < width; ++j) {
                if (j < i)
                    cout << "/";
                else if (j == i)
                    cout << ">";
                else
                    cout << " ";
            }
            cout << "] " << (i * 100 / width) << "%\r";
            
            this_thread::sleep_for(chrono::milliseconds(40)); // Adjust speed here
        }
        cout << endl;
    }
    void showUI(){
        if (shop_mode) {
            cout << "|INVENTORY|" << "\033[31m" << " |STORE|" << "\033[0m" << "                                                                                                                                            " << "ITEM STATS" << endl;
            shop->showUI();
            if(show_help) cout << "ACTIONS" << endl << "+====================+" << endl << "| > buy item (B)     |" << endl << "| > exit store (T)   |" << endl << "+====================+" << endl;
            else cout << endl << "ACTIONS: To Open Actions menu tap 'H'" << endl << endl;
        }
        else {
            cout << "\033[31m" << "|INVENTORY|" << "\033[0m" << " |STORE|" << "                                                                                                                                            " << "ITEM STATS" << endl;
            player.showEq();
            if (show_help) cout << "ACTIONS" << endl << "+====================+" << endl << "| > HELP (H)         |" << endl << "| > move (WASD)      |" << endl << "| > use item (E)     |" << endl << "| > enter store (T)  |" << endl << "| > curse item (C)   |" << endl << "| > drop item (X)    |" << endl << "| > sell item (G)    |" << endl << "| > randomise (R)    |" << endl << "| > Save (K)         |" << endl << "| > load (L)         |" << endl << "| > unEquipWeapon (N)|" << endl << "| > unEquipArmor (M) |" << endl << "| > SortInventory (F)|" << endl << "| > OpenCase 500g (O)|" << endl << "+====================+" << endl;
            else cout << endl << "ACTIONS: To Open Actions menu tap 'H'" << endl << endl;
        }
    
        cout<<"PLAYER STATS"<<endl;
        player.getStats();
        cout<<"CONSOLE"<<endl;
        ShowConsole();
}
       
    void input() {
        char player_char_input;
        string player_string_input;
        cout << "commit input crime: ";
            // Read the pressed key
        player_char_input = _getch();
            switch (player_char_input)
            {
            case 'e':
                console.push_back(player.useItem());
                break;
            case 'c':
                if (shop_mode) console.push_back("Did you really tried to curse my item???");
                else console.push_back(player.curseItem());
                break;
            case 'x':
                console.push_back(player.dropItem());
                break;

            case 'w': case 'a': case 's': case 'd':
                if (shop_mode) {
                    shop->moveInStore(player_char_input);
                }
                else {
                    player.moveInEquipment(player_char_input);
                }
                break;
            case 't':
                shop_mode = !shop_mode;
                break;
            case 'b':
                if (shop_mode) {
                    console.push_back(shop->buyItem(player));
                }
                break;
            case 'g':
                console.push_back(player.sellItem());
                break;
            case 'f':
                if (shop_mode) console.push_back("Did you really tried to sort MY shop???");
                else console.push_back(player.sortInvertory());
                break;
            case 'v':
                if (shop_mode) console.push_back("Did you really tried to sort MY shop???");
                else console.push_back(player.sortByRarity());
                break;
            case 'm':
                console.push_back(player.unEquipArmor());
                break;
            case 'n':
                console.push_back(player.unEquipWeapon());
                break;
            case 'k':
                console.push_back(player.savePlayerToFile("Save.txt"));
                break;
            case 'l':
                console.push_back(player.readPlayerFromFile("Save.txt"));
                break;
            case 'r':
                if (shop_mode) console.push_back(shop->randomizeShop());
                else console.push_back(player.randomizeInventory());
                break;
            case 'o':
                console.push_back(player.OpenCase());
                break;
            case 'h':
                HelpMEPLS();
                break;
            case 'i':
                cout << endl << "Type what you want to do:" << endl;
                cin >> player_string_input;
                if (player_string_input == "help") HelpMEPLS();
                else if (player_string_input == "fuck_you" or player_string_input == "exit") gameLoop = false;
                else console.push_back("you commited a mistake or there no words like this in my library");
				break;
            }
    }

};

#endif
