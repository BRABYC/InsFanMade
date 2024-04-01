#ifndef ITEM_H //define ITEM_H for other files to use class Item
#define ITEM_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map> 

using namespace std;

int RandomiseRarity(int uncommonNum, int rareNum, int epicNum, int legendaryNum, int japierdoleNum) {
    int uncommonRand = rand() % uncommonNum;
    int rareRand = rand() % rareNum;
    int epicRand = rand() % epicNum;
    int legendaryRand = rand() % legendaryNum;
    int japierdoleRand = rand() % japierdoleNum;
    if (japierdoleRand == 1) {
        return 5;
    }
    else if (legendaryRand == 1) {
        return 4;
    }
    else if (epicRand == 1) {
        return 3;
    }
    else if (rareRand == 1) {
        return 2;
    }
    else if (uncommonRand == 1) {
        return 1;
    }
    else {
        return 0;
    }
};

int GetRarityStrange(string itemRarity) {
    if (itemRarity == "common") return 1;
    else if (itemRarity == "uncommon") return 2;
    else if (itemRarity == "rare") return 3;
    else if (itemRarity == "epic") return 4;
    else if (itemRarity == "legendary") return 5;
    else if (itemRarity == "Hakurei") return 6;
    else return -1;
};

class Item {
//attributes of the class
public:
    string name;
    int price;
    string curse;
    string rarity;
    map<int, string> rarities;
    vector<string> names1;
    vector<string> names2;
    vector<string> names3;
    
    Item(string name = "none", int price = 0, string curse = "none", string rarity = "none") : name{name}, price{price}, curse{curse}, rarity{rarity} {
        rarities = { {0, "common"}, {1, "uncommon"}, {2, "rare"}, {3, "epic"}, {4, "legendary"}, {5, "Hakurei"} };
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
            this->rarity = rarities[RandomiseRarity(20, 40, 80, 150, 1000)];
        }
        this->attack = ((rand() % 10) + 30) * GetRarityStrange(this->rarity);
        names1 = { "sword", "axe", "mace", "spear", "bow", "crossbow", "dagger", "staff", "wand", "club" };
        names2 = { "of the", "of"};
        names3 = { "flame", "ice", "lightning", "earth", "water", "wind", "darkness", "light", "holy", "unholy" };
        if (name == "none") {
            this->name = names1[rand() % names1.size()] + " " + names2[rand() % names2.size()] + " " + names3[rand() % names3.size()];
        }
        if (price == -1) {
            this->price = ((rand() % 10) + GetRarityStrange(this->rarity) * 10) * GetRarityStrange(this->rarity);
        }

   }

};
class Armor : public Item {
public:
    int defence;
    Armor(string name = "none", int defense = 10, int price = -1, string curse = "none", string rarity = "none") : Item(name, price, curse, rarity) {
        if (rarity == "none") {
            this->rarity = rarities[RandomiseRarity(20, 40, 80, 150, 1000)];
        }
        this->defence = ((rand() % 10) + 30) * GetRarityStrange(this->rarity);
        names1 = { "pain", "crimson", "shadow", "gaunt", "iron", "high priest's", "darkness", "femboy", "holy", "unholy" };
        names3 = { "chestplate", "robe", "helmet", "arm guards", "shoes", "thigh-highs", "bascinet", "cuirass", "robes", "outfit" };
        if (name == "none") {
            this->name = names1[rand() % names1.size()] + " " + names3[rand() % names3.size()];
        }
        if (price == -1) {
            this->price = ((rand() % 10) + GetRarityStrange(this->rarity) * 10) * GetRarityStrange(this->rarity);
        }
    }
};


#endif //end ITEM_H so nothing under this will be included