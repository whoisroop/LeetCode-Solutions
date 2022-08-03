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
    int path(TreeNode * node, int &maxP){
        if(node==NULL)  return 0;

        int ls = path(node->left, maxP);
        int rs = path(node->right, maxP);

        maxP = max(maxP, max(node->val, max(node->val + ls + rs, node->val + max(ls, rs))));  
        //For max we have 3 options:
        //Choose only the current node.
        //Choose both left and right branch: current node will be the anchor.
        //Choose any one branch.

        //Return only the single branch sum which will connect to the previous node to form a path.
        int branchSum = node->val + max(0, max(ls, rs));
        return branchSum;
    } 

    int maxPathSum(){
        TreeNode * root = createTree();
        int maxP = -1e8;

        path(root, maxP);

        cout << "MAXPATH SUM: " << maxP << endl;
        return maxP;
    }

};

int main(){
    Solution newSol;
    newSol.maxPathSum();

    return 0;
}