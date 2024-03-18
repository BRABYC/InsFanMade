#ifndef ITEM_H //define ITEM_H for other files to use class Item
#define ITEM_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Item {
//atribbutes of the class
public:
    string name;
    string type;
    int attack;
    int defense;
    int price;
    string curse;
    Item(string name = "item", string type = "weapon" ,int defense = 0, int attack = 0, int price = 10, string curse = "none") : name{ name }, type{ type }, defense{ defense }, attack{attack}, price{price}, curse{curse} {}
};

#endif //end ITEM_H so nothing under this will be included