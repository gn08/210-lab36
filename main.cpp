#include <iostream>
#include "IntBinaryTree.h"
#include <string>
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
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                cout << "Enter code: ";
                getline(cin, code);
                try{
                    int numericCode = stoi(code);
                    tree.insertNode(numericCode);
                    cout << "Code inserted" << endl;
                } catch (){

                } catch (){
                    
                }
                break;
            case 2:
                cout << "Codes in order: ";
                tree.displayInOrder();
                break;
            case 3:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Try again" << endl;
        }
    } while (choice != 3);
    return 0;
}