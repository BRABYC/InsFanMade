#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include "Storage.h"
#include "Player.h"
#include "Item.h"

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

        #include "Player.h"

        void buyItem(Player& player) {
            int x = storage->Xcoord;
            int y = storage->Ycoord;
            if(storage->grid[y][x] != nullptr) {
                player.addItem(storage->grid[y][x]); // Modify this line
                storage->grid[y][x] = nullptr;
            }
        }
        void moveInStore(char choice) {
            storage->moveInEquipment(choice);
        }
        void getItemStats(){
            storage->getItemStats();
        }


    


};
#endif