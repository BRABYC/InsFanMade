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
        cout <<"debug: equped before changing " << mainHand << " Item: " << (mainHand != nullptr ? mainHand->name : " nothing ") << endl;
        cout << "debug: item before changing " << eq->grid[x][y] << " Item: " << (eq->grid[x][y] != nullptr ? eq->grid[x][y]->name : " nothing ") << endl;
        mainHand = (eq->grid[x][y] == nullptr ? nullptr : eq->grid[x][y]);
        eq->grid[x][y] = temp;
        cout << "debug: equped after changing " << mainHand << " Item: " << (mainHand != nullptr ? mainHand->name : " nothing ") << endl;
    }
    //set main armor using coordinates x and y COUNT FROM 1 NOT 0
    void setMainArmor(int x, int y) {
        Item* temp = armor;
        cout << "debug: equped before changing " << armor << endl;
        cout << "debug: item before changing " << eq->grid[x][y] << endl;
        armor = (eq->grid[x][y] == nullptr ? nullptr : eq->grid[x][y]);
        eq->grid[x][y] = temp;
        cout << "debug: equped after changing " << armor << endl;
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
    void DoIHaveSomeFreeSpace() {
        cout << eq->DoIHaveSomeFreeSpace() << endl;
    }
    void useItem() {
        Item* current_item = eq->grid[eq->Xcoord][eq->Ycoord];
        if (current_item != nullptr) {

            if (current_item->type == "weapon") {
                setMainWeapon(eq->Xcoord, eq->Ycoord);
            }
            else if (current_item->type == "armor") {

                setMainArmor(eq->Xcoord, eq->Ycoord);
            }
        }
		else {
			cout << "here nothing to equip" << endl;
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
    void dropItem(){
       eq->grid[eq->Xcoord][eq->Ycoord] = nullptr;
    }
    //destructor to not have memory leaks
        //~Player() {
            //delete eq;  // Delete the Storage object
        //}
};
#endif