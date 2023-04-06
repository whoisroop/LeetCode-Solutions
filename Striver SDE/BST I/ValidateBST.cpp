// LeetCode - 98. Validate Binary Search Tree.
// Description - 

// Approach:
// A range restriction is imposed on every node in a BST. Use the range restriction to validate a BST.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkBST(TreeNode * node, long long int minV, long long int maxV){
        if(node == NULL) return true;
        int value = node->val;
        if(value <= minV || value >= maxV) return false;

        bool checkL = checkBST(node->left, minV, value);
        if(checkL == false) return false;
        bool checkR = checkBST(node->right, value, maxV);
        if(checkR == false) return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return checkBST(root, 1LL*INT32_MIN - 1, 1LL*INT32_MAX + 1);
    }
};

int main(){
    Solution solve;
    
    return 0;
}