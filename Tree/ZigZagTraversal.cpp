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
    vector<vector<int>> zigZag(){
        TreeNode * root = createTree();
        vector<vector<int>> traversal;
        queue<TreeNode *> q;
        
        if(root == NULL)    return traversal;

        q.push(root);
        bool takeReverse = false;   //For every even level reverse the traversal
        while(q.empty() != true){
            int size = q.size();
            vector<int> level;
            TreeNode * node = NULL;

            for(int i=0; i<size; i++){
                node = q.front(); q.pop();
                level.push_back(node->val);

                if(node->left!=NULL)    q.push(node->left);
                if(node->right!=NULL)   q.push(node->right);
            }

            if(takeReverse) reverse(level.begin(), level.end());
            takeReverse = (!takeReverse);

            traversal.push_back(level);
        }

        for(int i=0; i<traversal.size(); i++){
            for(int j=0; j<traversal[i].size(); j++)   cout << traversal[i][j] << " ";
            cout << endl;
        }

        return traversal;
    }

};

int main(){
    Solution traversal;
    traversal.zigZag();
}