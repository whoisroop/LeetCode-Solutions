// GFG - Construct Binary Tree from Parent Array.
// Description - Given an array of size N that can be used to represents a tree. The array indexes are values in tree nodes and array values give the parent node of that particular index (or node). The value of the root node index would always be -1 as there is no parent for root. Construct the standard linked representation of Binary Tree from this array representation.
// Note: If two elements have the same parent, the one that appears first in the array will be the left child and the other is the right child. 

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N){
        unordered_map<int, Node *> pmap;    //Pointer Map
        
        Node * root = NULL;
        for(int i=0; i<N; i++){
            Node * node = new Node(i);
            pmap[i] = node;
        }
        
        for(int i=0; i<N; i++){
            int pValue = parent[i];
            if(pValue == -1){ root = pmap[i]; continue; }
            
            if(pmap[pValue]->left == NULL) pmap[pValue]->left = pmap[i];
            else pmap[pValue]->right = pmap[i];
        }
        
        return root;
    }
};

int main(){
    Solution solve;
    
    return 0;
}