#ifndef STORAGE_H //define STORAGE_H for other files to use class Equipment
#define STORAGE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Item.h"// Add the necessary include path for the "Item.h" header file
#include <tuple>
#include <algorithm>
using namespace std;

class Storage {
    int rows;
    int cols;
public:
    int Xcoord = 0;
    int Ycoord = 0;
    Item*** grid; //defina a 2D array of pointers to Item objects
    Storage(int rows = 5, int cols = 5) : rows{rows}, cols{cols} {
        grid = new Item**[rows]; //every array now has a array
        for(int i = 0; i < rows; i++) {
            grid[i] = new Item*[cols]; //every array now has a array
        }
        //fill the grid with items
        int count = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int whatToAdd = rand()% 3;
                if(whatToAdd == 0) grid[i][j] = new Weapon();
                else if(whatToAdd == 1) grid[i][j] = new Armor();
                else grid[i][j] = nullptr;
                count++;
            }
        }
        
    }

    int getRows() {
		return rows;
    }

    int getCols() {
		return cols;
    }
    //display the grid
    void display() {
    for (int i = 0; i < rows; i++) {
        cout << "| ";
        for (int j = 0; j < cols; j++) {
            if (i == Xcoord && j == Ycoord) {
                cout << "\033[31m"; // Set color to red
                cout << left << setw(30) << (grid[i][j] != nullptr ? grid[i][j]->name : "[ ] ");
                cout << "\033[0m"; // Reset color
            } else {
                cout << left << setw(30) << (grid[i][j] != nullptr ? grid[i][j]->name : "[ ] ");
            }
        }
        cout << " |" << endl;
    }
}
        tuple<int, int> DoIHaveSomeFreeSpace() { //for returning multiple values
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
            if(Xcoord != this->cols-1){
                Xcoord++;
            }
            break;
        
        case 'a':
            if(Ycoord != 0){
                Ycoord--;
            }
            break;
        
        case 'd':
            if(Ycoord != this->rows-1){
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
            cout << "+========================+" << endl;

            // Adjusted setw to fit within 23 characters, including borders and spaces
            cout << "| Name: " << left << setw(17) << current_item->name << "|" << endl;
            cout << "| Curse: " << left << setw(16) << current_item->curse << "|" << endl;
            if (dynamic_cast<Weapon*>(current_item)) {
                Weapon* weapon = dynamic_cast<Weapon*>(current_item);
                cout << "| Attack: " << left << setw(15) << weapon->attack << "|" << endl;
            }
            else if (dynamic_cast<Armor*>(current_item)) {
                Armor* armor = dynamic_cast<Armor*>(current_item);
                cout << "| Defence: " << left << setw(14) << armor->defence << "|" << endl;
            }

            cout << "| Price: " << left << setw(16) << current_item->price << "|" << endl;

            cout << "+========================+" << endl;
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
        // If either item is nullptr, place it after the other
        if (item1 == nullptr) return false;
        if (item2 == nullptr) return true;

        return item1->price < item2->price;
    }

    string sortInventory() {
        // Create a temporary array to hold all non-null items
        vector<Item*> tempItems;

        // Extract all non-null items from the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != nullptr) {
                    tempItems.push_back(grid[i][j]);
                }
            }
        }

        // Sort the items using the static compare function
		for (int i = 0; i < tempItems.size(); i++) {
			for (int j = i + 1; j < tempItems.size(); j++) {
				if (compareByPrice(tempItems[i], tempItems[j])) {
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

        return "Inventory sorted in descending order of price";
    }
};

#endif // STORAGE_H
