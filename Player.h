#ifndef PLAYER_H //define PLAYER_H for other files to use class Player
#define PLAYER_H

#include <iostream>
#include <string>   
#include <vector>
#include "Item.h"
#include "Storage.h" 
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
        weaponCurses = {"burning", "ice", "holy light", "fumo blessing", "bloodlust","grotesque" };
        armorCurses = {"reinforced", "bloodstained","gaunt", "light", "flimsy" };
    }
    //set main weapon using coordinates x and y COUNT FROM 1 NOT 0
    void setMainWeapon(int x, int y) {
        Item* temp = mainHand;
        cout << mainHand << endl;
        cout << eq->grid[y][x] << endl;
        temp = eq->grid[y][x];
        eq->grid[y][x] = mainHand;
        mainHand = temp;
        cout << mainHand << endl;
    }
    //set main armor using coordinates x and y COUNT FROM 1 NOT 0
    void setMainArmor(int x, int y) {
        Item* temp = armor;
        cout << armor << endl;
        cout << eq->grid[y][x] << endl;
        temp = eq->grid[y][x];
        eq->grid[y][x] = armor;
        armor = temp;
        cout << armor << endl;
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
    void useItem(){
        Item* current_item = eq->grid[eq->Xcoord][eq->Ycoord];
        if(current_item->type == "weapon"){
            setMainWeapon(eq->Xcoord, eq->Ycoord);
        }
        else if(current_item->type == "armor"){
            setMainArmor(eq->Xcoord, eq->Ycoord);
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
    string addItem(Item* item){
        int rows = eq->getRows();
        int cols = eq->getCols();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(eq->grid[i][j] == nullptr){
                    eq->grid[i][j] = item;
                    return "item added";
                }
            }

        }
    }
    string dropItem(){

    }
    //destructor to not have memory leaks
        //~Player() {
            //delete eq;  // Delete the Storage object
        //}
};
#endif