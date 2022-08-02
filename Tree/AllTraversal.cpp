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
    //Keep a count on number of times you're returning to a node.
    vector<vector<int>> DFS(){
        TreeNode * root = createTree();
        stack<pair<TreeNode *, int>> stk;
        vector<int> preorder, inorder, postorder;
        vector<vector<int>> traversals;

        if(root==NULL)  return traversals; //Return Empty Vector

        stk.push({root, 1});
        while(stk.empty()!=true){
            auto element = stk.top();
            TreeNode * node = element.first;
            int count = element.second;

            if(count==1){  //Preorder - Element visited first time
                stk.pop();
                stk.push({node, count+1});  //Increase count of current node.

                preorder.push_back(node->val);
                if(node->left!=NULL)    stk.push({node->left, 1});
            }

            else if(count==2){
                stk.pop();
                stk.push({node, count+1});

                inorder.push_back(node->val);
                if(node->right!=NULL)   stk.push({node->right, 1});
            }

            else{   //Count - 3
                stk.pop();  //Do not reinsert

                postorder.push_back(node->val);
            }
        }

        traversals.push_back(preorder);
        traversals.push_back(inorder);
        traversals.push_back(postorder);

        return traversals;
    }

};

int main(){
    vector<vector<int>> traversals;
    Solution newSol;

    traversals = newSol.DFS();
    for(int i=0; i<traversals.size(); i++){
        if(i==0)    cout << "PREORDER: ";
        if(i==1)    cout << "INORDER: ";
        if(i==2)    cout << "POSTORDER: ";
        for(int j=0; j<traversals[i].size(); j++)   cout << traversals[i][j] << " ";
        cout << endl;
    }

    return 0;
}