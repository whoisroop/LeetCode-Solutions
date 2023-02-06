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
    //Counting Number Of Nodes: Edges = Nodes - 1.
    int traverse(TreeNode * node, int &diameter){
        if(node == NULL) return 0;
        
        int pathA = 1 + traverse(node->left, diameter);
        int pathB = 1 + traverse(node->right, diameter);
        
        diameter = max(diameter, (pathA + pathB));  //Anchor Point
        return max(pathA, pathB);
    }

    int diameter(TreeNode* root) {
        if(root == NULL) return 0;
        int diameter = 0;
        traverse(root, diameter);
        return (diameter - 1);
    }
};