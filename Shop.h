#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include "Storage.h"
#include "Player.h"
#include "Item.h"
#include <tuple>
#include <vector>

using namespace std;

class Shop {
    private:
        Storage* storage;
    public:
        Shop() {
            storage = new Storage();
        }

        void showUI() {
            cout <<"+=============================================================================+" << endl;
            storage->display();
            cout <<"+=============================================================================+" << endl;
        }


    string buyItem(Player& player) {
        int x, y;
        if (storage->grid[storage->Xcoord][storage->Ycoord] != nullptr) {
            tie(x, y) = player.DoIHaveSomeFreeSpace();
            if (x == -1 && y == -1) {
                return "No space in inventory";
            } else {
                if(player.doesThePlayerHaveTheGold(storage->grid[storage->Xcoord][storage->Ycoord]->price)){
                    Storage* eq = player.getStorage();
                    eq->grid[x][y] = storage->grid[storage->Xcoord][storage->Ycoord];
                    storage->grid[storage->Ycoord][storage->Xcoord] = nullptr;
                    storage->dropItem();
                    return "Bought item";
                }
                else{
                    return "Not enough gold";
                }
            }
        }
        return "oh yes i am an error, uwu boy władzio should fix me rigth up~";
    }   

        void moveInStore(char choice) {
            storage->moveInEquipment(choice);
        }

        void getItemStats(){
            storage->getItemStats();
        }  


};
#endif