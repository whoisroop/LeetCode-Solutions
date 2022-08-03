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
    vector<int> preOrder(){
        TreeNode * root = createTree();
        vector<int> preorder;
        stack<TreeNode *> stk;
        //Root Left Right

        if(root==NULL)  return preorder;
        
        stk.push(root);
        while(stk.empty()!=true){
            TreeNode * node = stk.top();
            preorder.push_back(node->val);
            stk.pop();

            if(node->right!=NULL) stk.push(node->right);
            if(node->left!=NULL) stk.push(node->left);
        }

        cout << "\nPre Order: ";
        for(int i: preorder)    cout << i << " ";

        return preorder;
    }

    vector<int> postOrder(){
        TreeNode * root = createTree();
        vector<int> postorder;
        stack<TreeNode *> stk;
        //Left Right Root --> Reverse ( Root Right Left )

        if(root==NULL)  return postorder;

        stk.push(root);
        while(stk.empty()!=true){
            TreeNode * node = stk.top();
            postorder.push_back(node->val);
            stk.pop();

            if(node->left!=NULL)    stk.push(node->left);
            if(node->right!=NULL)   stk.push(node->right);
        }

        reverse(postorder.begin(), postorder.end());
        cout << "\nPost Order: ";
        for(int i: postorder) cout << i << " ";

        return postorder;
    }

    //Keep in mind the axuliary stack space during recursion & use a node pointer to traverse and push the required node into the stack. 
    vector<int> inOrder(){
        TreeNode * root = createTree();
        vector<int> inorder;
        stack<TreeNode *> stk;
        //Left Root Right

        if(root==NULL)  return inorder;

        TreeNode * node = root;
        while(true){
            if(node!=NULL){
                //If the current node is not null go to the left of the current node. As the parent of next node is the current node push it into the stack so as when we return to the same node --> the left part would have been traversed, then push the element into traversal & move onto the right of that node but pop out the parent node as we do not wish to visit it again.
                stk.push(node); 
                node = node->left;
            }
            else{
                //Node == Null: The left subtree is completed.
                if(stk.empty()==true)   break;
                node = stk.top();
                stk.pop();
                inorder.push_back(node->val);

                node = node->right;
            }
        }

        cout << "\nIn Order: ";
        for(int i: inorder) cout << i << " ";
        
        return inorder;
    }
};

int main(){
    Solution traversal;

    traversal.preOrder();
    traversal.inOrder();
    traversal.postOrder();

    return 0;
}