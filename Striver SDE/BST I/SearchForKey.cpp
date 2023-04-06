// LeetCode - 700. Search in a Binary Search Tree.
// Description - You are given the root of a binary search tree (BST) and an integer val.
// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        
        TreeNode * node = root;
        while(node){
            if(node->val == val) return node;

            if(node->val > val) node = node->left;
            else node = node->right;
        }

        return NULL;
    }
};

int main(){
    Solution solve;
    
    return 0;
}