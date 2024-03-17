#ifndef STORAGE_H //define STORAGE_H for other files to use class Equipment
#define STORAGE_H

#include <iostream>
#include <string>
#include "Item.h"// Add the necessary include path for the "Item.h" header file

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
                grid[i][j] = new Item("item " + to_string(count));
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
        for(int i = 0; i < rows; i++) {
            cout<<"| ";
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == grid[Xcoord][Ycoord]){
                    cout << "[" << "\033[31m"<< (grid[i][j] != nullptr ? grid[i][j]->name : "none") << "\033[0m" << "]";
                }
                else{
                    cout << "[" << (grid[i][j] != nullptr ? grid[i][j]->name : "none") << "]";
                }
                cout << "\t ";
            }
            cout << " |" << endl;
        }
    }

    void deleteItem(int x, int y) {
        delete grid[x][y];
        grid[x][y] = nullptr;
    }
    
    //deconstructor to free up memory
    ~Storage() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                delete grid[i][j];
            }
        }
        for (int j = 0; j < rows; j++) {
            delete[] grid[j];
        }
        delete[] grid;
    }
};

#endif // STORAGE_H
