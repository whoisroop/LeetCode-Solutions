// Problem - https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
// Link - https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
// Description - Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.

#include<bits/stdc++.h>
using namespace std;

Node * kth(Node * current, int &target, int &counter){
    if(current->data == target) return current;
    
    Node * L = NULL;
    Node * R = NULL;
    if(current->left) L = kth(current->left, target, counter);
    if(current->right) R = kth(current->right, target, counter);
    
    if(L != NULL || R != NULL){ counter -= 1; }
    
    if(counter == 0) return current;
    else if(L != NULL) return L;
    else if(R != NULL) return R;
    else return NULL;
}

int kthAncestor(Node *root, int K, int node){
    if(root == NULL) return -1;
    Node * ancestor = kth(root, node, K);
    return (K <= 0) ? (ancestor->data) : -1; 
}

int main(){
    Solution solve;
    
    return 0;
}