//Find the max width of a binary tree.
//The max width is the max number of (possible) nodes between two nodes at a level.
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

    int maxWidth(){
        TreeNode * root = createTree();
        queue<pair<TreeNode *, int>> q; //The node & indexing 1 2 3 ... 
        //            1
        //          /   \
        //        2       3
        int maxi = INT32_MIN;
        
        if(root == NULL) return 0;

        q.push({root, 1});
        while(!q.empty()){
            int size = q.size();
            int fi = q.front().second;  //First index of the element in the level.

            long int difference = 0;
            for(int j=0; j<size; j++){
                auto nodex = q.front(); q.pop();
                TreeNode * node = nodex.first;
                int i = nodex.second;

                difference = (1LL*i - fi) + 1;    //Difference of indexing + 1: Total max possible nodes in a level also called the width.

                if(node->left != NULL) q.push({node->left, (2*1LL)*i});
                if(node->right != NULL) q.push({node->right, (2*1LL)*i+1});
            }
            
            maxi = max(maxi, (int)difference);
        }

        return maxi;
    }

};

int main(){
    Solution tree;
    cout << tree.maxWidth();
    return 0;
}