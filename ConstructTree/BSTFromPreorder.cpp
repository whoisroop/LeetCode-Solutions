// LeetCode - 1008. Construct Binary Search Tree from Preorder Traversal.
// Description - 

// Approach:
// PREORDER: N L R
// Preorder = [8,5,1,7,10,12]
// Root = 8 & The right subtree has the value greater than parent node, therefore find the first element greater than the ROOT.
// Preorder = Root: 8 | Left: (5 1 7) | Right: (10 12)
// Repeat the process recursively.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode * createBST(int start, int end, vector<int> &preorder){
        if(start > end) return NULL;

        TreeNode * node = new TreeNode(preorder[start]);
        int index = end + 1;
        for(int i=start; i<=end; i++) if(preorder[i] > preorder[start]){index = i; break;}

        node->left = createBST(start + 1, index - 1, preorder);
        node->right = createBST(index, end, preorder);

        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return createBST(0, preorder.size()-1, preorder);    
    }
};

int main(){
    Solution solve;
    
    return 0;
}