#ifndef PLAYER_H //define PLAYER_H for other files to use class Player
#define PLAYER_H

#include <iostream>
#include <string>   
#include "Item.h"
#include "Storage.h" 
class Player {
    int HP;
    int gold;
    int damage;
    int defence;
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
    //destructor to not have memory leaks
        //~Player() {
            //delete eq;  // Delete the Storage object
        //}
};
#endif