#ifndef PLAYER_H
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
    Player() {
        HP = 100;
        mainHand = nullptr;
        armor = nullptr;
        eq = new Equipment();
    }
    void setMainWeapon(int i, int j) {
        Item* temp = mainHand;
        mainHand = eq->grid[i][j];
        eq->grid[i][j] = temp;
    }
    void setMainArmor(int i, int j) {
        Item* temp = armor;
        armor = eq->grid[i][j];
        eq->grid[i][j] = temp;
    }
    void showEq() {
        eq->display();
    }
    void displayPlayerStats() {
        cout << "HP: " << HP << endl;
        cout << (mainHand != nullptr ? mainHand->name : "none") << endl;
        cout << (armor != nullptr ? armor->name : "none") << endl;
        eq->display();
    }
    ~Player() {
        delete eq;
    }
};
#endif