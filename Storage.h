#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Item.h"
#include <tuple>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_GRAY    "\x1b[90m"
#define ANSI_COLOR_PURPLE  "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_WHITE   "\x1b[37m"

using namespace std;

class Storage {
    int rows;
    int cols;
public:
    int Xcoord = 0;
    int Ycoord = 0;
    Item*** grid;

    Storage(int rows = 5, int cols = 5) : rows{rows}, cols{cols} {
        grid = new Item**[rows];
        for(int i = 0; i < rows; i++) {
            grid[i] = new Item*[cols];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = nullptr;
            }
        }
    }

    int getRows() {
        return rows;
    }

    int getCols() {
        return cols;
    }

    void saveInventoryToFile(const string& filename) {
        ofstream outfile(filename);
        if (outfile.is_open()) {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (grid[i][j] != nullptr) {
                        if (dynamic_cast<Weapon*>(grid[i][j])) {
                            Weapon* weapon = dynamic_cast<Weapon*>(grid[i][j]);
                            outfile << "weapon," << weapon->name << "," << weapon->price << "," << weapon->attack << "," << weapon->curse << "," << weapon->rarity << endl;
                        }
                        else if (dynamic_cast<Armor*>(grid[i][j])) {
                            Armor* armor = dynamic_cast<Armor*>(grid[i][j]);
                            outfile << "armor," << armor->name << "," << armor->price << "," << armor->defence << "," << armor->curse << "," << armor->rarity << endl;
                        }
                    }
                    else {
                        outfile << "empty" << endl;
                    }
                }
            }
            cout << "Inventory saved to file." << endl;
        }
        else {
            cout << "Error: Unable to open file for saving inventory." << endl;
        }
        outfile.close();
    }

    void readInventoryFromFile(const string& filename) {
        ifstream infile(filename);
        if (infile.is_open()) {
            string line;
            int row = 0, col = 0;
            while (getline(infile, line)) {
                if (line == "empty") {
                    grid[row][col] = nullptr;
                }
                else {
                    stringstream ss(line);
                    string type;
                    getline(ss, type, ',');
                    if (type == "weapon") {
                        string name;
                        int price, attack;
                        string curse, rarity;
                        getline(ss, name, ',');
                        ss >> price;
                        ss.ignore(); // Ignore the comma
                        ss >> attack;
                        ss.ignore(); // Ignore the comma
                        getline(ss, curse, ',');
                        getline(ss, rarity);
                        grid[row][col] = new Weapon(name, attack, price, curse, rarity);
                    }
                    else if (type == "armor") {
                        string name;
                        int price, defense;
                        string curse, rarity;
                        getline(ss, name, ',');
                        ss >> price;
                        ss.ignore(); // Ignore the comma
                        ss >> defense;
                        ss.ignore(); // Ignore the comma
                        getline(ss, curse, ',');
                        getline(ss, rarity);
                        grid[row][col] = new Armor(name, defense, price, curse, rarity);
                    }
                }
                col++;
                if (col >= cols) {
                    col = 0;
                    row++;
                    if (row >= rows) {
                        break;
                    }
                }
            }
            cout << "Inventory loaded from file." << endl;
        }
        else {
            cout << "Error: Unable to open file for reading inventory." << endl;
        }
        infile.close();
    }

    void randomizeInventory() {
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                int whatToAdd = rand() % 3;
                if (whatToAdd == 0) grid[i][j] = new Weapon();
                else if (whatToAdd == 1) grid[i][j] = new Armor();
                else grid[i][j] = nullptr;
            }
        }
    }

    void display() {
        string color;
        cout << "+========================================================================================================================================================+   +================================+" << endl;
        for (int i = 0; i < rows; i++) {
            cout << "| ";
            for (int j = 0; j < cols; j++) {
                if (i == Xcoord && j == Ycoord) {
                    color = ANSI_COLOR_RED;
                    
                }
                else if (grid[i][j] != nullptr && grid[i][j]->rarity != "Hakurei") {
                    color = getRarityColor(grid[i][j]->rarity);
                }
                else {
                    color = ANSI_COLOR_WHITE;
                }
                cout << color;
                cout << left << setw(30) << (grid[i][j] != nullptr ? grid[i][j]->name : "[ ] ");
                cout << ANSI_COLOR_RESET;
            }
            cout << " |";
            if (grid[Xcoord][Ycoord] != nullptr) {
                Item* current_item = grid[Xcoord][Ycoord];
                if(i == 0) cout << "   | Name: " << left << setw(25) << current_item->name << "|" << endl;
                else if(i == 1) cout << "   | Curse: " << left << setw(24) << current_item->curse << "|" << endl;
                else if (i == 2) {
                    if (dynamic_cast<Weapon*>(current_item)) {
                        Weapon* weapon = dynamic_cast<Weapon*>(current_item);
                        cout << "   | Attack: " << left << setw(23) << weapon->attack << "|" << endl;
                    }
                    else if (dynamic_cast<Armor*>(current_item)) {
                        Armor* armor = dynamic_cast<Armor*>(current_item);
                        cout << "   | Defence: " << left << setw(22) << armor->defence << "|" << endl;
                    }
                }
                
                else if(i == 3) cout << "   | Price: " << left << setw(24) << current_item->price << "|" << endl;
                else if(i == 4) cout << "   | rarity: " << left << setw(23) << current_item->rarity << "|" << endl;
                else if (i == 5) cout << "   +================================+" << endl;
                else cout << endl;
                
            }
            else {
                if (i == 0) cout << "   | Nothing                        |" << endl;
                else if (i == 1) cout << "   +================================+" << endl;
                else cout << endl;

            }
        }
        cout << "+========================================================================================================================================================+" << endl;
    }

    tuple<int, int> DoIHaveSomeFreeSpace() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == nullptr) {
                    return make_tuple(i, j);
                }
            }
        }
        return make_tuple(-1, -1);
    }

    void moveInEquipment(char choice){
        cout<<this->Xcoord<<endl;
        switch (choice){
        case 'w':
            if(Xcoord != 0){
                Xcoord--;
            }
            break;

        case 's':
            if(Xcoord != this->rows-1){
                Xcoord++;
            }
            break;
        
        case 'a':
            if(Ycoord != 0){
                Ycoord--;
            }
            break;
        
        case 'd':
            if(Ycoord != this->cols-1){
                Ycoord++;
            }
            break;
                    
        default:
            break;
        }
    }

    void getItemStats(){
        if (grid[Xcoord][Ycoord] != nullptr) {
            Item* current_item = grid[Xcoord][Ycoord];
            cout << "+================================+" << endl;
            cout << "| Name: " << left << setw(25) << current_item->name << "|" << endl;
            cout << "| Curse: " << left << setw(24) << current_item->curse << "|" << endl;
            if (dynamic_cast<Weapon*>(current_item)) {
                Weapon* weapon = dynamic_cast<Weapon*>(current_item);
                cout << "| Attack: " << left << setw(23) << weapon->attack << "|" << endl;
            }
            else if (dynamic_cast<Armor*>(current_item)) {
                Armor* armor = dynamic_cast<Armor*>(current_item);
                cout << "| Defence: " << left << setw(22) << armor->defence << "|" << endl;
            }
            cout << "| Price: " << left << setw(24) << current_item->price << "|" << endl;
            cout << "| rarity: " << left << setw(23) << current_item->rarity << "|" << endl;
            cout << "+================================+" << endl;
        }
        else {
            cout << "+====================+" << endl;
            cout << "| Nothing            |" << endl;
            cout << "+====================+" << endl;
        }

    }

    string dropItem(){
        if(grid[Xcoord][Ycoord] != nullptr){
            grid[Xcoord][Ycoord] = nullptr;
            return "Item dropped";
        }
        else{
            return "There is no item to drop";
        }
    }

    bool compareByPrice(const Item* item1, const Item* item2) {
        if (item1 == nullptr) return false;
        if (item2 == nullptr) return true;
        return item1->price < item2->price;
    }

    string sortInventory() {
        vector<Item*> tempItems;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != nullptr) {
                    tempItems.push_back(grid[i][j]);
                }
            }
        }
        for (int i = 0; i < tempItems.size(); i++) {
            for (int j = i + 1; j < tempItems.size(); j++) {
                if (compareByPrice(tempItems[i], tempItems[j])) {
                    swap(tempItems[i], tempItems[j]);
                }
            }
        }
        int index = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (index < tempItems.size()) {
                    grid[i][j] = tempItems[index++];
                }
                else {
                    grid[i][j] = nullptr;
                }
            }
        }
        return "Inventory sorted in descending order of price";
    }



    bool compareByRarity(Item* item1, Item* item2) {
        if (item1 == nullptr) return false;
        if (item2 == nullptr) return true;

        // Retrieve the rarity values for each item
        int rarity1 = item1->rarities[item1->rarity];
        int rarity2 = item2->rarities[item2->rarity];

        // Compare the rarity values
        return rarity1 < rarity2;
    }


    string sortByRarity() {
        vector<Item*> tempItems;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != nullptr) {
                    tempItems.push_back(grid[i][j]);
                }
            }
        }
        // Sort the items using the custom comparison function
        for (int i = 0; i < tempItems.size(); i++) {
            for (int j = i + 1; j < tempItems.size(); j++) {
                if (compareByRarity(tempItems[i], tempItems[j])) {
                    swap(tempItems[i], tempItems[j]);
                }
            }
        }

        // Re-populate the grid with the sorted items
        int index = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (index < tempItems.size()) {
                    grid[i][j] = tempItems[index++];
                }
                else {
                    grid[i][j] = nullptr;
                }
            }
        }

        return "Inventory sorted in ascending order of rarity";
    }


    // Function to determine color based on rarity
    string getRarityColor(const string& rarity) {
        if (rarity == "common") {
            return ANSI_COLOR_GRAY;
        }
        else if (rarity == "uncommon") {
            return ANSI_COLOR_CYAN;
        }
        else if (rarity == "rare") {
            return ANSI_COLOR_BLUE;
        }
        else if (rarity == "epic") {
            return ANSI_COLOR_PURPLE;
        }
        else if (rarity == "legendary") {
            return ANSI_COLOR_YELLOW;
        }
        else {
            return ANSI_COLOR_WHITE;
        }
    }
};

#endif // STORAGE_H
