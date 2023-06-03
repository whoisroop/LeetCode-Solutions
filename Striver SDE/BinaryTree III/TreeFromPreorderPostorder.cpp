// GFG - Construct a Full Binary Tree.
// Description - Given two arrays that represent Preorder traversals of a Full binary tree preOrder[] and its mirror tree preOrderMirror[], your task is to complete the function constructBinaryTree(), that constructs the full binary tree using these two Preorder traversals.

// Note: It is not possible to construct a general binary tree using these two traversal. But it is possible to create a full binary tree using the above traversals without any ambiguity.
//      0           0
//    /               \ 
//  1                   1
//    \               / 
//      2           2

// Both the trees will have same preorder & postorder.

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node * left;
    Node * right;

    Node(int aValue){
        value = aValue;
    } 
};

class Solution{
public:
    // PREORDER:    N L R
    // POSTORDER:   L R N
    Node * create(int i, int j, vector<int> &preorder, vector<int> &postorder){
        if(i > j) return NULL;
        if(i == j){
            int nValue = postorder[j];
            Node * node = new Node(nValue);
            node->left = NULL;
            node->right = NULL;
            return node;
        }
        
        int nValue = postorder[j];
        Node * node = new Node(nValue);
        
        int index = 0;
        for(int p=0; p<preorder.size(); p++) if(preorder[p] == nValue){ index = p; break; }
        index += 1; //Left
        
        int breakpoint = 0;
        for(int p=j-1; p>=i; p--) if(postorder[p] == preorder[index]){ breakpoint = p; break; }
        
        node->left = create(i, breakpoint, preorder, postorder);
        node->right = create(breakpoint+1, j-1, preorder, postorder);
        
        return node;
    }
    
    Node * constructBinaryTree(int P[], int PM[], int N)
    {
        vector<int> preorder(N, 0);
        vector<int> postorder(N, 0);
        for(int i=0; i<N; i++){
            preorder[i] = P[i];
            postorder[i] = PM[(N-1) - i];
        }
        
        return create(0, N-1, preorder, postorder);
    }
};

int main(){
    Solution solve;
    
    return 0;
}