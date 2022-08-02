#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
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
public:
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

    int treeHeight(TreeNode * node){
        if(node==NULL)  return 0;

        int left = 1 + treeHeight(node->left);
        int right = 1 + treeHeight(node->right);

        return max(left, right);
    }

};

int main(){
    Solution tree;
    TreeNode * root = tree.createTree();
    cout << tree.treeHeight(root);

    return 0;
}