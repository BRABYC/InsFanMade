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

class Game {
private:
    Player player;
    bool shop_mode;
    bool show_help;
    Shop* shop;
    vector<string> console;

public:
    Game(const Player& player) : player(player) {
        shop_mode = false;
		show_help = false;
        shop = new Shop();
        console.resize(5);
    }

    void HelpMEPLS() {
        if (show_help) show_help = false; 
		else show_help = true;
    }

    void showUI(){
        if (shop_mode) {
            cout << "|INVENTORY|" << "\033[31m" << " |STORE|" << "\033[0m" << endl;
            shop->showUI();
            cout << "ITEM STATS" << endl;
            shop->getItemStats();
            if(show_help) cout << "ACTIONS" << endl << "+====================+" << endl << "| > buy item (B)     |" << endl << "| > exit store (T)   |" << endl << "+====================+" << endl;
        }
        else {
            cout << "\033[31m" << "|INVENTORY|" << "\033[0m" << " |STORE|" << endl;
            player.showEq();
            cout << "ITEM STATS" << endl;
            player.getItemStats();
            if (show_help) cout << "ACTIONS" << endl << "+====================+" << endl << "| > HELP (H)         |" << endl << "| > move (WASD)      |" << endl << "| > use item (E)     |" << endl << "| > enter store (T)  |" << endl << "| > curse item (C)   |" << endl << "| > drop item (X)    |" << endl << "| > sell item (G)    |" << endl << "| > randomise (R)    |" << endl << "| > Save (K)         |" << endl << "| > load (L)         |" << endl << "| > unEquipWeapon (N)|" << endl << "| > unEquipArmor (M) |" << endl << "| > SortInventory (F)|" << endl << "| > OpenCase 500g (O)|" << endl << "+====================+" << endl;
        }
    
        cout<<"PLAYER STATS"<<endl;
        player.getStats();
        cout<<"CONSOLE"<<endl;
        cout<<"+====================================================================================================================================+"<<endl;
        if(console.size() > 5){
            console.erase(console.begin());
        }
        for (int i = 0; i < console.size(); i++) {
            cout << "| ";        
            cout << left << setw(130) << console[i];
            cout << " |" << endl;
        }
        cout<<"+====================================================================================================================================+"<<endl;
}

    void input() {
        char player_input;
        cout << "commit input crime: ";
            // Read the pressed key
            player_input = _getch();
            switch (player_input)
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
                    shop->moveInStore(player_input);
                }
                else {
                    player.moveInEquipment(player_input);
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
                console.push_back(player.saveInventory());
                break;
            case 'l':
                console.push_back(player.loadInventory());
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
            }
    }

};

#endif
