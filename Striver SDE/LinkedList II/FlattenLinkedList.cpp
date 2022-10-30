// GeekForGeek - Flattening A Linked List.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data = 0;
    struct Node * next = NULL;
    struct Node * bottom = NULL;

    Node(int aData){
        data = aData;
    }
    
    Node(){}
};

// Approach: 
// The bottom linked list is sorted: Recursively merge two sorted linked list.
// First merge the last node & last second node's bottom linked list.
// Then merge it with its previous.

class Solution{
public:
    Node * mergeList(Node * pA, Node * pB){
        Node * start = new Node(-1);
        Node * pC = start;
        
        while(pA!=NULL && pB!=NULL){
            if(pA->data <= pB->data){
                pC->bottom = pA;
                pA = pA->bottom;
            }
            else{
                pC->bottom = pB;
                pB = pB->bottom;
            }

            pC = pC->bottom;
        }
        
        if(pA) pC->bottom = pA;
        if(pB) pC->bottom = pB;
        
        return (start->bottom);
    }

    Node * flatten(Node * node){
        if(node == NULL) return NULL;
        
        node->next = flatten(node->next);
        return mergeList(node, node->next);
    }
};