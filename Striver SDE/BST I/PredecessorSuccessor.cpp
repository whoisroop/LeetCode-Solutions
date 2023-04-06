// GFG - There is BST given with root node with key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.
// Note :- In an inorder traversal the number just smaller than target is predecessor and the number just greater than target is successor.

// SAME AS FLOOR & CEIL OF BST.

// Description - 

#include<bits/stdc++.h>
using namespace std;

void findPS(Node* root, Node*& P, Node*& S, int value){
    P = NULL; S = NULL;
    if(root == NULL) return;
    
    // Successor:
    Node * node = root;
    while(node){
        if(node->key > value){ S = node; node = node->left; }
        else node = node->right;
    }
    
    // Predecessor:
    node = root;
    while(node){
        if(node->key < value){ P = node; node = node->right; }
        else node = node->left;
    }
    
    return;
}

int main(){
    Solution solve;
    
    return 0;
}