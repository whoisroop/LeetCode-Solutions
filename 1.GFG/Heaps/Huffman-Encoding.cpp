// Problem - Huffman Encoding 
// Link - https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

// To optimise space complexity we use huffman encoding scheme, where the characters with high frequency are alloted small binary values.
// We extract the small valued nodes & join them to create a new node with value (L + R frequencies) and push it back to the heap.
// Keep repeating till one node is left in the heap, root node.
// Travelling left alot '0' to it & travelling right alot '1' to the link and derive the values.

// abaccada
// d - 1
// b - 1
// c - 2
// a - 4

// POP (d, b)
// PUSH( (d, b) - 1 + 1 )

// (d,b) - 2
// c     - 2
// a     - 4

// POP((d,b) , c)
// PUSH( ((d,b), c) - 2 + 2 )

// ((d,b),c) - 4
// a         - 4

// POP(((d,b),c), a)
// PUSH( ((d,b),c), a) - 4 + 4 )

// ((d,b),c), a) - 4    TREE

// From ROOT - Move Left ((d,b),c) Move Right a
// From ((d,b),c) - Move Left (d,b) Move Right c
// From (d,b) - Move Left d Move Right b

// a - 0
// c - 10
// d - 111
// b - 110

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char value;
    Node * left;
    Node * right;
    
    Node(char aValue){ 
        value = aValue; 
        left = NULL; 
        right = NULL; 
    }
};

class comparator{
public:
    bool operator()(pair<int, Node*> &A, pair<int, Node*> &B){
        return (A.first > B.first);
    }
};

class Solution{
private:
    void pcode(Node * current, string pattern, vector<string> &codes){
        if(current->left == NULL && current->right == NULL){ 
            codes.push_back(pattern); return;
        }
        
        if(current->left) pcode(current->left, pattern+'0', codes);
        if(current->right) pcode(current->right, pattern+'1', codes);
        
        return;
    }
    
public:
	vector<string> huffmanCodes(string A, vector<int> F, int N){
	    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, comparator> minheap;
	    for(int i=0; i<N; i++){
	        Node * nnode = new Node(A[i]);
	        minheap.push({F[i], nnode});
	    }
	    
	    while(minheap.size() > 1){
	        auto A  = minheap.top(); minheap.pop();
	        auto B = minheap.top(); minheap.pop();
	        
	        Node * nnode = new Node('*');
	        nnode->left = A.second;
	        nnode->right = B.second;
	        minheap.push({A.first+B.first, nnode});
	    } Node * head = minheap.top().second;
	    
	    vector<string> solution;
	    pcode(head, "", solution);
	    
	    return solution;
	}
};

int main(){
    Solution solve;
    
    return 0;
}