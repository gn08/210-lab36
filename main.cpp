#include <iostream>
#include "IntBinaryTree.h"
#include <string>
using namespace std;

void displayMenu(){
    cout << endl << "Menu: " << endl;
    cout << "1. Insert code " << endl;
    cout << "2. Display codes in order " << endl;
    cout << "3. Search code " << endl;
    cout << "5. Modify code" << endl;
    cout << "6. Exit" << endl;
     
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
            case 1:{
                cout << "Enter code: ";
                getline(cin, code);
                tree.insertNode(code);
                cout << "Code inserted" << endl;
                break;
            }
            case 2: {
                cout << "Codes in order: " << endl;
                tree.displayInOrder();
                cout << endl;
                break;
            }
            case 3:{
                cout << "Enter code to search: " << endl;
                getline(cin, code);
                if (tree.searchNode(code)) {
                    cout << "Code found" << endl;
                } else {
                    cout << "Code not found" << endl;
                }
                break;
            }
            case 4:{
                cout << "Enter code to delete: " << endl;
                getline(cin, code);
                tree.remove(code);
                cout << "Code deleted" << endl;
                break;
            }
            case 5:{
                cout << "Enter code to modify: "
                string oldCode, newCode;
                getline(cin, oldCode);
                if (tree.searchNode(oldCode)) {
                    cout << "Enter new code: ";
                    getline(cin, newCode);
                    tree.remove(oldCode);
                    tree.insertNode(newCode);
                    cout << "Code modified" << endl;
                } else {
                    cout << "Code not found" << endl;
                }
                break;
            }
            case 6:{
                cout << "Exiting" << endl;
                break;
            }
            default:{
                cout << "Try again" << endl;
                break;
            }
        }
    } while (choice != 3);
    return 0;
}