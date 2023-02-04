// LeetCode -
// Description - 

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int aVal){
        val = aVal;
        left = NULL;
        right = NULL;
    }
};

//  TREE:
//            1
//          /   \
//        2       3
//      /   \    
//    4       5
//          /   \
//        6       7


class Solution{
private:
    TreeNode * createTree(){
        TreeNode * root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->left->right->left = new TreeNode(6);
        root->left->right->right = new TreeNode(7);

        return root;
    }

public:
    vector<int> inorder(){
        TreeNode * root = createTree();
        if(root == NULL) return {};

        stack<pair<TreeNode *, int>> stk;
        vector<int> inorderT;

        stk.push({root, 1});
        // N L R - Keep in mind while counting
        while(!stk.empty()){
            TreeNode * node = stk.top().first;
            int count = stk.top().second;   //Read count before updating.

            stk.pop(); stk.push({node, count + 1}); //Update Count.

            if(count == 1){
                if(node->left != NULL) stk.push({node->left, 1});
            }
            else if(count == 2){
                inorderT.push_back(node->val);
                if(node->right != NULL) stk.push({node->right, 1});
            }
            else{
                stk.pop();
            }
        }

        return inorderT;
    }

};

int main(){
    Solution solve;
    
    return 0;
}