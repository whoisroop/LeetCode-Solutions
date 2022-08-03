//Concept of vertical traversal.
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
    vector<int> topView(){
        TreeNode * root = createTree();
        vector<int> traversal;
        map<int, int> mpp;  //mpp[x coordinate] = TopMost Element
        queue<pair<TreeNode *, int>> q; //Queue to store node & x coordinate.

        if(root == NULL)    return traversal;

        q.push({root, 0});
        while(q.empty()!=true){
            int size = q.size();

            for(int i=0; i<size; i++){
                auto nodex = q.front(); q.pop();
                TreeNode * node = nodex.first;
                int x = nodex.second;

                //Only store the first element traversed for the x coordinate when encountered traversing level wise.
                if(mpp.find(x)==mpp.end()) mpp[x]=node->val;    //Check if it already exists.

                if(node->left!=NULL)    q.push({node->left, x-1});
                if(node->right!=NULL)    q.push({node->right, x+1});
            }
        }

        for(auto &i: mpp)   traversal.push_back(i.second);  //Already stored in ascending order.

        for(int &i: traversal)   cout << i << " ";
        return traversal;
    }

};

int main(){
    Solution view;
    view.topView();
}