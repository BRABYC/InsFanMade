#ifndef ITEM_H //define ITEM_H for other files to use class Item
#define ITEM_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map> 

using namespace std;

string RandomiseRarity(int uncommonNum, int rareNum, int epicNum, int legendaryNum, int japierdoleNum) {
    int uncommonRand = rand() % uncommonNum;
    int rareRand = rand() % rareNum;
    int epicRand = rand() % epicNum;
    int legendaryRand = rand() % legendaryNum;
    int japierdoleRand = rand() % japierdoleNum;
    if (japierdoleRand == 1) {
        return "Hakurei";
    }
    else if (legendaryRand == 1) {
        return "legendary";
    }
    else if (epicRand == 1) {
        return "epic";
    }
    else if (rareRand == 1) {
        return "rare";
    }
    else if (uncommonRand == 1) {
        return "uncommon";
    }
    else {
        return "common";
    }
};


class Item {
//attributes of the class
public:
    string name;
    int price;
    string curse;
    string rarity;
    map<string, int> rarities;
    vector<string> names1;
    vector<string> names2;
    vector<string> names3;
    
    Item(string name = "none", int price = 0, string curse = "none", string rarity = "none") : name{name}, price{price}, curse{curse}, rarity{rarity} {
        rarities = { {"common", 1}, {"uncommon", 2}, {"rare", 4}, {"epic", 7}, {"legendary", 15}, {"Hakurei", 35} };
    }
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
    Weapon(string name = "none", int attack = 10, int price = -1, string curse = "none", string rarity = "none") : Item(name, price, curse, rarity) {
        if (rarity == "none") {
            this->rarity = RandomiseRarity(20, 40, 80, 150, 1000);
        }
        this->attack = ((rand() % 10) + 30) * rarities[this->rarity];
        names1 = { "sword", "axe", "mace", "spear", "bow", "crossbow", "dagger", "staff", "wand", "club" };
        names2 = { "of the", "of"};
        names3 = { "flame", "ice", "lightning", "earth", "water", "wind", "darkness", "light", "holy", "unholy" };
        if (name == "none") {
            this->name = names1[rand() % names1.size()] + " " + names2[rand() % names2.size()] + " " + names3[rand() % names3.size()];
        }
        if (price == -1) {
            this->price = ((rand() % 10) + rarities[this->rarity] * 10) * rarities[this->rarity];
        }

   }

};
class Armor : public Item {
public:
    int defence;
    Armor(string name = "none", int defense = 10, int price = -1, string curse = "none", string rarity = "none") : Item(name, price, curse, rarity) {
        if (rarity == "none") {
            this->rarity = RandomiseRarity(20, 40, 80, 150, 1000);
        }
        this->defence = ((rand() % 10) + 30) * rarities[this->rarity];
        names1 = { "pain", "crimson", "shadow", "gaunt", "iron", "high priest's", "darkness", "femboy", "holy", "unholy" };
        names3 = { "chestplate", "robe", "helmet", "arm guards", "shoes", "thigh-highs", "bascinet", "cuirass", "robes", "outfit" };
        if (name == "none") {
            this->name = names1[rand() % names1.size()] + " " + names3[rand() % names3.size()];
        }
        if (price == -1) {
            this->price = ((rand() % 10) + rarities[this->rarity] * 10) * rarities[this->rarity];
        }
    }
};


#endif //end ITEM_H so nothing under this will be included