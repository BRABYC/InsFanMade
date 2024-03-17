#ifndef ITEM_H //define ITEM_H for other files to use class Item
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item {
//atribbutes of the class
public:
    string name;
    string type;
    int attack;
    int defense;
    Item(string name, string type, int defense, int attack) : name{ name }, type{ type }, defense{ defense }, attack{attack} {}
};

#endif //end ITEM_H so nothing under this will be included