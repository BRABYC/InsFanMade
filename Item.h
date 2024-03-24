#ifndef ITEM_H //define ITEM_H for other files to use class Item
#define ITEM_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Item {
//attributes of the class
public:
    string name;
    int price;
    string curse;
    vector<string> names1;
    vector<string> names2;
    vector<string> names3;
    Item(string name = "none" , int price = 0, string curse = "none") : name{ name }, price{price}, curse{curse} {}
    virtual ~Item() {} // Virtual destructor, needed for polymorphism, so that classes that derive from item can acces it and be considerd similar to Item

    virtual void applyCurse(const string& curse) {
        if (this->curse == "none") {
            this->curse = curse;
        }
    }
};

class Weapon : public Item {
public:
    int attack;
   Weapon(string name = "none", int attack = 10, string curse = "none") : Item(name, price, curse) {
        this->attack = rand() % 10 + 30;
        names1 = { "sword", "axe", "mace", "spear", "bow", "crossbow", "dagger", "staff", "wand", "club" };
        names2 = { "of the", "of"};
        names3 = { "flame", "ice", "lightning", "earth", "water", "wind", "darkness", "light", "holy", "unholy" };
        if (name == "none") {
            this->name = names1[rand() % names1.size()] + " " + names2[rand() % names2.size()] + " " + names3[rand() % names3.size()];
        }
        this->price = rand() % 10;
   }
};
class Armor : public Item {
public:
    int defence;
    Armor(string name = "none", int defense = 10, int price = 10, string curse = "none") : Item(name, price, curse) {\
        this->defence = rand() % 10 + 30;
        names1 = { "pain", "crimson", "shadow", "gaunt", "iron", "high priest's", "darkness", "femboy", "holy", "unholy" };
        names3 = { "chestplate", "robe", "helmet", "arm guards", "shoes", "thigh-highs", "bascinet", "cuirass", "robes", "outfit" };
        if (name == "none") {
            this->name = names1[rand() % names1.size()] + " " + names3[rand() % names3.size()];
        }
    }
};


#endif //end ITEM_H so nothing under this will be included