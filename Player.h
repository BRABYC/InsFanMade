#ifndef PLAYER_H //define PLAYER_H for other files to use class Player
#define PLAYER_H

#include <iostream>
#include <string>   
#include <vector>
#include "Item.h"
#include "Storage.h" 
#include <tuple>
using namespace std;
class Player {
    int HP;
    int gold;
    int damage;
    int defence;
    vector<string> weaponCurses;
    vector<string> armorCurses;
    Item* mainHand;
    Item* armor;
    Storage* eq;
public:
    //constructor to initialize the player's HP to 100 and the mainHand and armor to nullptr
    Player() {
        HP = 100;
        mainHand = nullptr;
        armor = nullptr;
        eq = new Storage();
        gold = 100;
        weaponCurses = {"burning", "ice", "holy light", "fumo blessing", "bloodlust","grotesque" };
        armorCurses = {"reinforced", "bloodstained","gaunt", "light", "flimsy" };
    }
    //set main weapon using coordinates x and y COUNT FROM 1 NOT 0
    void setMainWeapon(int x, int y) {
        Item* temp = mainHand;
        mainHand = (eq->grid[x][y] == nullptr ? nullptr : eq->grid[x][y]);
        eq->grid[x][y] = temp;
    }
    //set main armor using coordinates x and y COUNT FROM 1 NOT 0
    void setMainArmor(int x, int y) {
        Item* temp = armor;
        armor = (eq->grid[x][y] == nullptr ? nullptr : eq->grid[x][y]);
        eq->grid[x][y] = temp;
    }
    //display the player's inventory
    void showEq() {
        cout <<"+=============================================================================+" << endl;
        eq->display();
        cout <<"+=============================================================================+" << endl;
    }
        //cout << (mainHand != nullptr ? mainHand->name : "none") << endl;
        //cout << (armor != nullptr ? armor->name : "none") << endl;
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
    string useItem() {
        Item* current_item = eq->grid[eq->Xcoord][eq->Ycoord];
        if (current_item != nullptr) {

            if (current_item->type == "weapon") {
                Item* temp = mainHand;
                setMainWeapon(eq->Xcoord, eq->Ycoord);
                addItem(temp);
                return "Weapon equipped";
            }
            else if (current_item->type == "armor") {
                Item* temp = armor;
                setMainArmor(eq->Xcoord, eq->Ycoord);
                addItem(temp);
                return "Armor equipped";

            }
        }
    }
    string curseItem(){
        Item* current_item = eq->grid[eq->Xcoord][eq->Ycoord];
        if(current_item->curse == "none"){
            if(current_item->type == "weapon"){
                current_item->curse = weaponCurses[rand() % 6];
            }
            else if(current_item->type == "armor"){
                current_item->curse = armorCurses[rand() % 5];
            }
            else{
                return "you can't curse this item";
            }
        }
        return "you pray to all-mer... your prayer has been anwsered";
    
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
        cout << "+=====================================+" << endl;
        cout << "| HP:            " << left << setw(20) << HP << " |" << endl;
        cout << "| Gold:          " << left << setw(20) << gold << " |" << endl;
        cout << "| Damage:        " << left << setw(20) << damage << " |" << endl;
        cout << "| Defence:       " << left << setw(20) << defence << " |" << endl;
        cout << "| equipped weapon: " << left << setw(18) << (mainHand != nullptr ? mainHand->name : "none") << " |" << endl;
        cout << "| equipped armor:  " << left << setw(18) << (armor != nullptr ? armor->name : "none") << " |" << endl;
        cout << "+=====================================+" << endl;
    }
    //destructor to not have memory leaks
        //~Player() {
            //delete eq;  // Delete the Storage object
        //}
};
#endif