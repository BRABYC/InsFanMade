#include <iostream>
#include <string>
using namespace std;

#ifndef ITEM_H
#define ITEM_H
class Item {
public:
    string name;
    Item(string name) : name{name} {}
};

#endif