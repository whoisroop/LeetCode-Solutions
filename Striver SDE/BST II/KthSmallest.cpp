// GFG - Given a BST and an integer K. Find the Kth Smallest element in the BST using O(1) extra space.
// Description - 

// Approach:
// The inorder traversal of a BST is in sorted format.
// Use a counter to count the number of nodes visited & find the required Nth node.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void inorder(Node * node, int &N, int &value){
        if(node == NULL) return;
        
        inorder(node->left, N, value);
        N = N - 1;
        if(N == 0){ value = node->data; return; }
        inorder(node->right, N, value);
    }

    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        int value = -1;
        inorder(root, K, value);
        return value;
    }
};

int main(){
    Solution solve;
    
    return 0;
}