#ifndef PLAYER_H //define PLAYER_H for other files to use class Player
#define PLAYER_H

#include <iostream>
#include <string>   
#include "Item.h"
#include "Equipment.h" 
class Player {
    int HP;
    Item* mainHand;
    Item* armor;
    Equipment* eq;
public:
    //constructor to initialize the player's HP to 100 and the mainHand and armor to nullptr
    Player() {
        HP = 100;
        mainHand = nullptr;
        armor = nullptr;
        eq = new Equipment();
    }
    //set main weapon using coordinates x and y COUNT FROM 1 NOT 0
    void setMainWeapon(int x, int y) {
        Item* temp = mainHand;
        mainHand = eq->grid[y - 1][x - 1];
        eq->grid[y - 1][x - 1] = temp;
    }
    //set main armor using coordinates x and y COUNT FROM 1 NOT 0
    void setMainArmor(int i, int j) {
        Item* temp = armor;
        armor = eq->grid[i][j];
        eq->grid[i][j] = temp;
    }
    //display the player's inventory
    void showEq() {
        cout <<"+===========================================+" << endl;
        eq->display();
        cout <<"+===========================================+" << endl;
    }
    //display the player's stats and inventory
    void displayPlayerStats() {
        cout << "HP: " << HP << endl;
        cout << (mainHand != nullptr ? mainHand->name : "none") << endl;
        cout << (armor != nullptr ? armor->name : "none") << endl;
        showEq();
    }
    //destructor to not have memory leaks
    ~Player() {
        delete eq;
    }
};
#endif