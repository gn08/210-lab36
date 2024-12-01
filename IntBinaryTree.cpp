// Implementation file for the IntBinaryTree class
#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

// insert accepts a TreeNode pointer and a pointer to a node.
// The function inserts the node into the tree pointed to by 
// the TreeNode pointer. This function is called recursively.
void IntBinaryTree::insert(TreeNode *&nodePtr, int value) {
   if (nodePtr == nullptr){
      nodePtr = new TreeNode(value);                  // Insert the node.
   } else if (value < nodePtr->value){
      insert(nodePtr->left, value);     // Search the left branch
   } else {
      insert(nodePtr->right, value);    // Search the right branch
   }
}

// insertNode creates a new node to hold num as its value,
// and passes it to the insert function.                  
void IntBinaryTree::insertNode(int num) {
   insert(root, num);
}

// destroySubTree is called by the destructor. It
// deletes all nodes in the tree.                
void IntBinaryTree::destroySubTree(TreeNode *nodePtr) {
   if (nodePtr) {
      destroySubTree(nodePtr->left);
      destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   

// searchNode determines if a value is present in  
// the tree. If so, the function returns true.     
// Otherwise, it returns false.                    
bool IntBinaryTree::searchNode(int num) const{
   TreeNode *nodePtr = root;

   while (nodePtr)    {
      if (nodePtr->value == num)
         return true;
      else if (num < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}
     

// deleteNode deletes the node whose value 
// member is the same as num.              
void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr) {
   if (num < nodePtr->value)
      deleteNode(num, nodePtr->left);
   else if (num > nodePtr->value)
      deleteNode(num, nodePtr->right);
   else
      makeDeletion(nodePtr);
}


// makeDeletion takes a reference to a pointer to the node 
// that is to be deleted. The node is removed and the      
// branches of the tree below the node are reattached.     
void IntBinaryTree::makeDeletion(TreeNode *&nodePtr) {
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr;

   if (!nodePtr)
      cout << "Cannot delete empty node.\n";
   else if (!nodePtr->right) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   } else if (!nodePtr->left) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

// The displayInOrder member function displays the values       
// in the subtree pointed to by nodePtr, via inorder traversal. 
void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}
