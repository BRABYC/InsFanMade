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

    void deleteItem(int x, int y){
        delete grid[x][y];
        grid[x][y] = nullptr;
    }
    void displayOneRow(int whatRow){
            cout<<"| ";
            for(int j = 0; j < cols; j++) {
                if(grid[whatRow][j] == grid[Xcoord][Ycoord]){
                    cout << "[" << "\033[31m"<< (grid[whatRow][j] != nullptr ? grid[whatRow][j]->name : "none") << "\033[0m" << "]";
                }
                else{
                    cout << "[" << (grid[whatRow][j] != nullptr ? grid[whatRow][j]->name : "none") << "]";
                }
                cout << "\t ";
            }
            cout << " |";
    }
    //deconstructor to free up memory
    ~Storage() {
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
};

#endif // STORAGE_H
