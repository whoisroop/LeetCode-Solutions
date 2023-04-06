// LeetCode - 235. Lowest Common Ancestor of a Binary Search Tree.
// Description - 

// If both the values lie on left move left & vice versa.
// The point where both the values doesn't lie on either left or right is the splitting point and hence, the LCA.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * node = root;

        int a = p->val, b = q->val;
        while(node){
            if(node->val > a && node->val > b) node = node->left;
            else if(node->val < a && node->val < b) node = node->right;
            else return node;
        }

        return NULL;
    }
};

int main(){
    Solution solve;
    
    return 0;
}