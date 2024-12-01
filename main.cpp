#include <iostream>
#include "IntBinaryTree.h"
#include <string>
using namespace std;

//dsiplayMenu() displays menu options
//Arguments: none
//returns: none
void displayMenu(){
    cout << endl << "Menu: " << endl;
    cout << "1. Insert code " << endl;
    cout << "2. Display codes in order " << endl;
    cout << "3. Search code " << endl;
    cout << "4. Delete code" << endl;
    cout << "5. Modify code" << endl;
    cout << "6. Exit" << endl;
     
}

//main() is starting point to interact wuth Binary tree
//Arguments: none
//returns: 0
int main() {
    //store string codes
    IntBinaryTree tree;
    //users choice
    int choice;
    //users string input
    string code;

    do{
        //shows menu and collects input
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:{
                //insert new code into binary tree
                cout << "Enter code: ";
                getline(cin, code);
                tree.insertNode(code);
                cout << "Code inserted" << endl;
                break;
            }
            case 2: {
                //codes in order
                cout << "Codes in order: " << endl;
                tree.displayInOrder();
                cout << endl;
                break;
            }
            case 3:{
                //searches for codes
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
                //deletes code inputed
                cout << "Enter code to delete: " << endl;
                getline(cin, code);
                tree.remove(code);
                cout << "Code deleted" << endl;
                break;
            }
            case 5:{
                //modifies code input
                cout << "Enter code to modify: ";
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
                //exit code
                cout << "Exiting" << endl;
                break;
            }
            default:{
                //if invalid iput
                cout << "Try again" << endl;
                break;
            }
        }
    } while (choice != 6);
    return 0;
}