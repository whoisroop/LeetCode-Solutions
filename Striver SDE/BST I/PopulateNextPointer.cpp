// LeetCode - 116. Populating Next Right Pointers in Each Node
// Description - You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition: Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node *> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* node = q.front(); q.pop();
                if(i < n-1) node->next = q.front();
                else node->next = NULL;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return root;
    }
};

int main(){
    Solution solve;
    
    return 0;
}