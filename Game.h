#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Shop.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
class Game {
private:
    Player player;
    bool shop_mode;
    Shop* shop;
    vector<string> console;

public:
    Game(const Player& player) : player(player) {
        shop_mode = false;
        shop = new Shop();
        console.resize(5);
    }
    void showUI(){
        //system("CLS"); <------------- nie działa :(
        if(shop_mode){
            cout<<"|INVENTORY|"<< "\033[31m"<<" |STORE|"<< "\033[0m"<<endl;  
            shop->showUI();
            cout<<"ITEM STATS"<<endl;
            shop->getItemStats();
            cout<<"ACTIONS"<< endl <<"+====================+"<<endl<< "| > buy item (B)     |"<<endl << "| > exit store (T)   |"<<endl<<"+====================+"<<endl;
        }
        else{
            cout<<"\033[31m"<<"|INVENTORY|"<<"\033[0m"<< " |STORE|"<<endl;
            player.showEq();
            cout<<"ITEM STATS"<<endl;
            player.getItemStats();
            cout<<"ACTIONS"<<endl;
            cout<<"+====================+"<<endl<< "| > move (WASD)      |"<<endl << "| > use item (E)     |"<<endl << "| > enter store (T)  |"<<endl<<"| > curse item (C)   |"<<endl<< "| > drop item (R)    |"<<endl<< "| > sell item (G)    |"<<endl<<"+====================+"<<endl;
        }
        cout<<"PLAYER STATS"<<endl;
        player.getStats();
        cout<<"CONSOLE"<<endl;
        cout<<"+=================================+"<<endl;
        if(console.size() > 5){
            console.erase(console.begin());
        }
        for (int i = 0; i < console.size(); i++) {
            cout << "| ";        
            cout << left << setw(30) << console[i];
            cout << " |" << endl;
        }
        cout<<"+=================================+"<<endl;
}

    void input(){
        char player_input;
        cout<<"commit input crime: ";
        cin>>player_input;
            switch(player_input)
            {
                case 'e':
                    console.push_back(player.useItem());
                    break;
                case 'c':
                    console.push_back(player.curseItem());
                    break;
                case 'x':
                    console.push_back(player.dropItem());
                    break;
                
                case 'w': case 'a': case 's': case 'd':
                    if(shop_mode){
                        shop->moveInStore(player_input);
                    }
                    else{
                        player.moveInEquipment(player_input);
                    }
                    break;
                case 't':
                    shop_mode = !shop_mode;
                    break;
                case 'b':
                    if(shop_mode){
                        console.push_back(shop->buyItem(player));
                    }
                    break;
                case 'g':                    
                    console.push_back(player.sellItem());
                    break;
                case 'f':
                    console.push_back(player.sortInvertory());
                    break;
                case 'h':
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
                    console.push_back(player.randomizeInventory());
                    break;
        }
    }
};

#endif
