// BOTTOM VIEW OF THE TREE.
// Intuition:
// Using level order traversal, index every index on vertical basis.
// For every vertical level update the value in the map. Eventually it'll the last indexed value in the map for a specific level.
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
    vector <int> bottomView(TreeNode *root) {
        if(root == NULL) return {};
        map<int, int> vmap; //Maps the vertical order to the value.
        queue<pair<TreeNode *, int>> q;
        
        q.push({root, 0}); vmap[0] = root->val;
        while(!q.empty()){
            int n = q.size();
            
            for(int i=0; i<n; i++){
                auto front = q.front(); q.pop();
                TreeNode * node = front.first; int index = front.second;
                vmap[index] = node->val;
                
                if(node->left) q.push({node->left, index-1});
                if(node->right) q.push({node->right, index+1});
            }
        }
        
        vector<int> view;
        for(auto &i: vmap) view.push_back(i.second);
        return view;
    }

};