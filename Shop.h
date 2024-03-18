#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include "Storage.h"

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
        void moveInStore(char input) {
            storage->moveInEquipment(input);
            getItemStats();
        }
        void getItemStats() {
            storage->getItemStats();
        }


    


};
#endif