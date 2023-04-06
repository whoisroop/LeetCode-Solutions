// LeetCode - 101. Symmetric Tree.
// Description - 

#include<bits/stdc++.h>
using namespace std;

// Simultaneously Traverse The Left & The Right SUB-TREE. Root Left Right & Root Right Left.
class Solution {
public:
    bool traverse(TreeNode * A, TreeNode * B){
        if(A == NULL || B == NULL) return A == B;

        if(A->val != B->val) return false;
        if(traverse(A->left, B->right) == false) return false;
        if(traverse(A->right, B->left) == false) return false;

        return true;
    }
    
    bool isSymmetric(TreeNode * root) {
        if(root == NULL) return false;
        return traverse(root->left, root->right);
    }
};

int main(){
    Solution solve;
    
    return 0;
}