#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    Item(string name) : name{name} {}
};

class Equipment {
    Item*** grid;
    int rows;
    int cols;
public:
    Equipment(int rows = 5, int cols = 5) : rows{rows}, cols{cols} {
        grid = new Item**[rows];
        for(int i = 0; i < rows; i++) {
            grid[i] = new Item*[cols];
        }
        int count = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                grid[i][j] = new Item("item " + to_string(count));
                count++;
            }
        }
    }
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
    void display() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cout << "[" << grid[i][j]->name << "]\t";
            }
            cout << endl;
        }
    }

};

int main()
{
    Equipment E;
    E.display();

    return 0;
}
