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
    //Using (preorder traversal) height concept to check for the height difference of left & right subtree.
    int f(TreeNode * node){ 
        if(node == NULL)    return 0;
        
        int left = f(node->left);
        if(left==-1)  return -1;
        int right = f(node->right);
        if(right==-1)  return -1;
        
        if(abs(left-right)>1)    return -1; //If not a balanced binary tree --> Return -1.
        else return (max(left, right) + 1); //Else return the height of the tree.
        
    }
    
    bool isBalanced() {
        TreeNode * root = createTree();
        if(f(root)==-1) return false;
        else return true;
    }

};

int main(){
    Solution newSol;
    cout << newSol.isBalanced();

    return 0;
}