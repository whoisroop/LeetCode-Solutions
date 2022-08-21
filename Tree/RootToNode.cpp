//Find root to node path.
//Implemented using inorder traversal.
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

    int findPathRecursion(TreeNode * node, int value, vector<int> & path){
        if(node == NULL) return 0;
        if(node->val == value) { path.push_back(node->val); return -1;}

        path.push_back(node->val);
        // for(int i: path) cout << i << " ";
        // cout << endl;
        int left = findPathRecursion(node->left, value, path);
        if(left == -1) return -1;
        int right = findPathRecursion(node->right, value, path);
        if(right == -1) return -1;
        path.pop_back();

        return 0;
    }

    void findPath(){
        TreeNode * root = createTree();
        int findValue = 7;
        vector<int> path;
        
        findPathRecursion(root, findValue, path);
        for(int i: path) cout << i << " ";

        return;
    }

};

int main(){
    Solution tree;
    tree.findPath();

    return 0;
}