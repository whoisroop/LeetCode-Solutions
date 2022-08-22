//Convert the given binary tree into any tree that follow the property:
//Sum of parent = Sum of its children.
//You can only increment value of nodes.
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
    //METHOD I:
    //One of the method is to find the max value in the binary tree & replace the leaf values with the max value & find the sum of parent nodes.
    //METHOD II:    c: childrens (l + r)
    //While traversing to the children nodes: if(sumOfC < sumOfP) make, value of c = value of p
    //else make the value of parent = sum of its children.
    //In this way there's no decrementing needed.

    int makeBT(TreeNode * node){
        if(node->left==NULL && node->right==NULL) return node->val;

        int sum = 0;
        if(node->left!=NULL) sum += node->left->val;
        if(node->right!=NULL) sum += node->right->val;

        if(sum < node->val){
            if(node->left!=NULL) node->left->val = sum;
            if(node->right!=NULL) node->right->val = sum;
        }

        int l=0, r=0;
        if(node->left!=NULL) l = makeBT(node->left);
        if(node->left!=NULL) r = makeBT(node->right);

        node->val = l+r;
        return (l+r);
    }

    void printTree(){
        TreeNode * root = createTree();
        makeBT(root);

        queue<TreeNode *> q;
        q.push(root);
        while(q.empty()!=true){
            int size = q.size();

            for(int i=0; i<size; i++){
                TreeNode * node = q.front(); q.pop();
                cout << node->val << " ";

                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }

            cout << endl;
        }
    }
};

int main(){
    Solution tree;
    tree.printTree();
    return 0;
}