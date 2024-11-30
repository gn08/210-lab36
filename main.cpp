#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

void displayMenu(){
    cout << endl << "Menu: " << endl;
    cout << "1. Insert code " << endl;
    cout << "2. Display codes in order " << endl;
    cout << "3. Exit " << endl;
}

int main() {
    IntBinaryTree tree;
    int choice;
    string code;

    do{

        switch(choice){
            case 1:
                //
            case 2:
                //
            case 3:
                //
            default:
                cout << "Try again" << endl;
        }
    } while (choice != 3);
    return 0;
}