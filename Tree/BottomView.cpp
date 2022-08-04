//Concept of vertical order traversal.
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
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
    vector<int> bottomView(){
        TreeNode * root = createTree();
        vector<int> traversal;
        map<int, int> mpp;  //mpp[x coordinate] = Last Value On That Vertical
        queue<pair<TreeNode *, int>> q;
        
        if(root==NULL)  return traversal;

        q.push({root, 0});  //Node & X
        while(q.empty()!=true){
            int size = q.size();

            for(int i=0; i<size; i++){
                auto nodex = q.front(); q.pop();
                TreeNode * node = nodex.first;
                int x = nodex.second;

                //We are traversing level wise so last updated will the last node in that vertical.
                mpp[x]=node->val;

                if(node->left!=NULL)    q.push({node->left, x-1});
                if(node->right!=NULL)   q.push({node->right, x+1});   
            }
        }

        for(auto &i: mpp)   traversal.push_back(i.second);

        for(int i: traversal)   cout << i << " ";

        return traversal;   
    }

};

int main(){
    Solution view;
    view.bottomView();

    return 0;
}