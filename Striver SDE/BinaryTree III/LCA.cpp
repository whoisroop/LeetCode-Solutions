// GFG - Lowest Common Ancestor.
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Traverse left & right subtree, if match found return true else false.
    // A node is the LCA if both left & right subtree returns true or any single & the node itself is a match!
    bool path(Node *node, int &a, int &b, Node * &LCA) {
        if (node == NULL) return false;

        bool pathA = path(node->left, a, b, LCA);
        bool pathB = path(node->right, a, b, LCA);
        
        bool current = (node->data == a || node->data == b);
        if (pathA && pathB || (pathA && current || pathB && current)) {
            LCA = node;
            return false;
        }
        
        return (pathA || pathB ) || current;
    }

    Node* LCA(Node* root, int valueA, int valueB)
    {
        if (root == NULL) return NULL;
        Node *LCA = NULL;
        path(root, valueA, valueB, LCA);
        return LCA;
    }
};

int main(){
    Solution solve;
    
    return 0;
}