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
    vector<int> verticalOrder(){
        TreeNode * root = createTree();
        vector<int> traversal;
        map<int, map<int, multiset<int>>> mpp;  //mpp[x coordinate][y coordinate] --> Values (MULTISET)
        queue<pair<TreeNode *, pair<int, int>>> q;  //Queue to store the node & their coordinates which later will be used to calculate coordinates of the children nodes.
        
        if(root == NULL)    return traversal;

        //First traverse through the nodes & mark their x,y coordinates.
        //Using level order traversal.
        q.push({root, {0,0}});
        while(q.empty()!=true){
            int size = q.size();

            for(int i=0; i<size; i++){
                auto nodex = q.front(); q.pop();
                TreeNode * node = nodex.first;
                pair<int, int> xy = nodex.second;
                mpp[xy.first][xy.second].insert(node->val);

                if(node->left!=NULL)    q.push({node->left, {xy.first-1, xy.second+1}});    //xy.first --> x
                if(node->right!=NULL)   q.push({node->right, {xy.first+1, xy.second+1}});
            }
        }

        for(auto &i: mpp){
            for(auto &j: i.second){
                for(auto &k: j.second)  {traversal.push_back(k);     cout << k << " ";}
            }
        }

        return traversal;
    }

};

int main(){
    Solution traversal;
    traversal.verticalOrder();
    return 0;
}