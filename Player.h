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
        cout <<" +=============================================================================+ " << endl;
        eq->display();
        cout <<" +=============================================================================+ " << endl;
    }
    //display the player's stats and inventory
    void displayPlayerStats() {
        cout << "HP: " << HP << endl;
        cout << (mainHand != nullptr ? mainHand->name : "none") << endl;
        cout << (armor != nullptr ? armor->name : "none") << endl;
        showEq();
    }
    void moveInEquipment(char choice){
        eq->moveInEquipment(choice);
    }
    void deleteItem(){
        int x, y;
        cout<<"Enter x: ";
        cin>>x;
        cout<<"Enter y: ";
        cin>>y;
        eq->deleteItem(x-1, y-1);
    }
    void displayOneRow(int i){
        eq->displayOneRow(i);
    }
    //destructor to not have memory leaks
    ~Player() {
        delete eq;
    }
};
#endif