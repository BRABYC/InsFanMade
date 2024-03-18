#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Shop.h"
#include <cstdlib>
class Game {
private:
    Player player;
    bool shop_mode;
    Shop* shop;
public:
    Game(const Player& player) : player(player) {
        shop_mode = false;
        shop = new Shop();
    }
    void showUI(){
        //system("CLS"); <------------- nie działa :(
        if(shop_mode){
            cout<<"|INVENTORY|"<< "\033[31m"<<" |STORE|"<< "\033[0m"<<endl;  
            shop->showUI();
            shop->getItemStats();
        }
        else{
            cout<<"\033[31m"<<"|INVENTORY|"<<"\033[0m"<< " |STORE|"<<endl;
            player.showEq();
            player.getItemStats();
        }
        cout<<"ITEM STATS"<<endl;
    }
    void input(){
        char player_input;
        cout<<"commit input crime: ";
        cin>>player_input;
        switch(player_input)
        {
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
            
        }

    }
};

#endif
