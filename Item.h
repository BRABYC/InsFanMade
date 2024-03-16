#ifndef ITEM_H //define ITEM_H for other files to use class Item
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item {
//atribbutes of the class
public:
    string name;
    Item(string name) : name{name} {}
};

#endif //end ITEM_H so nothing under this will be included