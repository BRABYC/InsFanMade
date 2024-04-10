#ifndef PLAYER_H //define PLAYER_H for other files to use class Player
#define PLAYER_H

#include <iostream>
#include <string>   
#include <vector>
#include "Item.h"
#include "Storage.h" 
#include <tuple>
#include <map> 
using namespace std;
class Player {
private:
    int HP;
    int gold;
    int damage;
    int defence;
    vector<string> weaponCurses;
    vector<string> armorCurses;
    Weapon* mainHand;
    Armor* armor;
    Storage* eq;
public:
    //constructor to initialize the player's HP to 100 and the mainHand and armor to nullptr
    Player() {
        HP = 100;
        mainHand = nullptr;
        armor = nullptr;
        eq = new Storage(7, 5);
        gold = 100;
        weaponCurses = {"burning", "ice", "holy light", "fumo blessing", "bloodlust","grotesque" };
        armorCurses = {"reinforced", "bloodstained","gaunt", "light", "flimsy" };
    }
    void showEq() {
        cout <<"+========================================================================================================================================================+" << endl;
        eq->display();
        cout <<"+========================================================================================================================================================+" << endl;
    }
    void moveInEquipment(char choice){
        eq->moveInEquipment(choice);
    }
    void getItemStats(){
        eq->getItemStats();
    }
    tuple<int, int>DoIHaveSomeFreeSpace() {
        int x,y;
        tuple<int, int> result = eq->DoIHaveSomeFreeSpace();
        tie(x, y) = result;
        if(x == -1 && y == -1){return make_tuple(-1, -1);}
        else{return make_tuple(x, y);}
    }

    string unEquipArmor() {
        int x, y;
        tie(x, y) = DoIHaveSomeFreeSpace();
        if (x == -1 && y == -1) {
            return "No space in inventory";
        }
        else {
            eq->grid[x][y] = armor;
			armor = nullptr;
            return "Armor has unequiped";
        }
    }

    string unEquipWeapon() {
        int x, y;
        tie(x, y) = DoIHaveSomeFreeSpace();
        if (x == -1 && y == -1) {
            return "No space in inventory";
        }
        else {
            eq->grid[x][y] = mainHand;
            mainHand = nullptr;
            return "Weapon has unequiped";
        }
    }
     string useItem() {
        Item* current_item = eq->grid[eq->Xcoord][eq->Ycoord];
        if (current_item != nullptr) {
            Weapon* weaponPtr = dynamic_cast<Weapon*>(current_item);
            if (weaponPtr != nullptr) {
                // Assuming mainHand is a Weapon*, swap it with the weaponPtr.
                std::swap(mainHand, weaponPtr);
                eq->grid[eq->Xcoord][eq->Ycoord] = weaponPtr; // Update the grid with the new (or old mainHand) item.
                return "You have equipped the weapon";
            }
            Armor* armorPtr = nullptr; // Declare the armorPtr variable
            armorPtr = dynamic_cast<Armor*>(current_item); // Assign the dynamic_cast result to armorPtr
            if (armorPtr != nullptr) {
                // Similarly, swap armor if armorPtr is valid.
                std::swap(armor, armorPtr);
                eq->grid[eq->Xcoord][eq->Ycoord] = armorPtr; // Update the grid.
                return "You have equipped the armor";
            }
            else {
                return "You can't equip this item";
            }
        }
        return "There's no item to use/equip here.";
    }
    string curseItem(){
        Item* current_item = eq->grid[eq->Xcoord][eq->Ycoord];
            if (!current_item) return "There's no item here to curse";

            if (current_item->curse != "none") {
                return "This item is already cursed";
            }

            Weapon* asWeapon = dynamic_cast<Weapon*>(current_item);
            if (asWeapon) {
                // If current_item is a Weapon, apply a weapon curse
                asWeapon->applyCurse(weaponCurses[rand() % weaponCurses.size()]);
                return "You pray to all-mer... your prayer has been answered, and the weapon is cursed";
            }

            Armor* asArmor = dynamic_cast<Armor*>(current_item);
            if (asArmor) {
                // If current_item is an Armor, apply an armor curse
                asArmor->applyCurse(armorCurses[rand() % armorCurses.size()]);
                return "You pray to all-mer... your prayer has been answered, and the armor is cursed";
            }

            // If current_item is neither Weapon nor Armor
            return "You can't curse this item";
        }
    void addItem(Item* item){
        int rows = eq->getRows();
        int cols = eq->getCols();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(eq->grid[i][j] == nullptr){
                    eq->grid[i][j] = item;
                }
            }

        }
    }
    string dropItem(){
       eq->dropItem();
       return "an item has been dropped";
    }
    Storage* getStorage(){
        return eq;
    }
    bool doesThePlayerHaveTheGold(int price){
        if(gold >= price){
            gold -= price;
            return true;
        }
        else{
            return false;
        }
    }
    string sellItem(){
        Item* current_item = eq->grid[eq->Xcoord][eq->Ycoord];
        if(current_item != nullptr){
            gold += current_item->price;
            eq->grid[eq->Xcoord][eq->Ycoord] = nullptr;
            return "item sold";
        }
        else{
            return "nothing to sell";
        }
    }
    void getStats() {
        cout << "+==========================================+" << endl;
        cout << "| HP:            " << left << setw(25) << HP << " |" << endl;
        cout << "| Gold:          " << left << setw(25) << gold << " |" << endl;
        cout << "| Damage:        " << left << setw(25) << damage + (mainHand != nullptr ? mainHand->attack : 0) << " |" << endl;
        cout << "| Defence:       " << left << setw(25) << defence + (armor != nullptr ? armor->defence : 0) << " |" << endl;
        cout << "| equipped weapon: " << left << setw(23) << (mainHand != nullptr ? mainHand->name : "none") << " |" << endl;
        cout << "| equipped armor:  " << left << setw(23) << (armor != nullptr ? armor->name : "none") << " |" << endl;
        cout << "+==========================================+" << endl;
    }

    string sortInvertory() {
		eq->sortInventory();
        return "Inventory sorted in descending order of price";
    }

    string sortByRarity() {
		eq->sortByRarity();
		return "Inventory sorted in descending order of rarity";
    }

    string saveInventory() {
        eq->saveInventoryToFile("InventorySave.txt");
        return "saved";
    }

    string loadInventory() {
        eq->readInventoryFromFile("InventorySave.txt");
        return "loaded";
    }

	string randomizeInventory() {
		eq->randomizeInventory();
		return "randomized";
    }
    
    string OpenCase() {
        int x, y;
        tie(x, y) = eq->DoIHaveSomeFreeSpace();
        if (x == -1 && y == -1) {
            return "No space in inventory";
        }
        else {
            if (doesThePlayerHaveTheGold(500)) {
                int whatToAdd = rand() % 1;
                vector<string> rarities = { "common", "uncommon", "rare", "epic", "legendary", "Hakurei" };
                string rarity = RandomiseRarity(1, 1, 10, 20, 40);;
                if (rarity == "common") rarity = rarities[2];
                if (whatToAdd == 0) eq->grid[x][y] = new Weapon("none", 10, -1, "none", rarity);
                else if (whatToAdd == 1) eq->grid[x][y] = new Armor("none", 10, -1, "none", rarity);
                return "Case opened";
            }
            else {
                return "Not enough gold";
            }
        }
    }
};
#endif