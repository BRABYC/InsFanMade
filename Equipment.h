#ifndef EQUIPMENT_H //define EQUIPMENT_H for other files to use class Equipment
#define EQUIPMENT_H

#include <iostream>
#include <string>
#include "Item.h"// Add the necessary include path for the "Item.h" header file

using namespace std;

class Equipment {
    int rows;
    int cols;
public:
    Item*** grid; //defina a 2D array of pointers to Item objects
    Equipment(int rows = 5, int cols = 5) : rows{rows}, cols{cols} {
        grid = new Item**[rows]; //every array now has a array
        for(int i = 0; i < rows; i++) {
            grid[i] = new Item*[cols]; //every array now has a array
        }
        //fill the grid with items
        int count = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                grid[i][j] = new Item("item " + to_string(count));
                count++;
            }
        }
    }
    //deconstructor to free up memory
    ~Equipment() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                delete grid[i][j];
            }
        }
        for(int j = 0; j < rows; j++) {
            delete[] grid[j];
        }
        delete[] grid;
    }
    //display the grid
    void display() {
        for(int i = 0; i < rows; i++) {
            cout<<"| ";
            for(int j = 0; j < cols; j++) {
                cout << "[" << (grid[i][j] != nullptr ? grid[i][j]->name : "none") << "]";
                cout << "\t ";
            }
            cout << " |" << endl;
        }
    }

};

#endif // EQUIPMENT_H
