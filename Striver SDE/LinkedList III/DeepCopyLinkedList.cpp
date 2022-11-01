// LeetCode - 138. Copy List With Random Pointer.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val = 0;
    struct Node * next = NULL;
    struct Node * random = NULL;

    Node(int aVal){
        val = aVal;
    }
    
    Node(){}
};

class Solution {
public:
    Node* deepCOPY(Node* head) {
        if(head == NULL) return NULL;
        
        unordered_map<Node *, Node *> pmap; //PointerMap: <Real List Node, Copied List Node>
        
        Node * start = new Node(-1);    //Start->Next : HEAD
        Node * i = head;
        Node * p = start;
        
        // Create a copy node with identical attributes.
        // Save the pointer to copy node & the real node.
        while(i!=NULL){
            Node * node = new Node(i->val);
            node->random = i->random;
            p->next = node;
            
            pmap[i] = node;
            p = p->next;
            i = i->next;
        }
        
        // Replace the pointer to real node by copy node using the map.
        p = start->next;
        while(p!=NULL){
            p->random = pmap[p->random];
            p = p->next;
        }
        
        return start->next;
    }
};