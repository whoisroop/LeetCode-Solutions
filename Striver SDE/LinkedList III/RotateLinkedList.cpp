// LeetCode - 61. Rotate List.

// 1 2 3 4 5 : ROTATE TWICE (K = 2)
// Length = 5, K = 2
// The Link Will Break At: Length - K = 3
// Point last node's next to first node. Iterate to third node in the list, this will be the last node.
// Point head to its next node, which will be first in the rotated list. Break the link between node & its next : Point node's next to NULL.

#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val = 0;
    struct ListNode * next = NULL;

    ListNode(int aVal, struct ListNode * aNext){
        val = aVal;
        next = aNext;
    }
    
    ListNode(){}
};

class Solution{
public:
    ListNode * rotateLinkedList(ListNode * head, int k){
        if(head == NULL || k<=0) return head;
        ListNode * p = head;

        int l=1;
        while(p->next != NULL){ l++; p = p->next; }
        //p points to the last: Which will point to the start of the node after rotation.
        
        int rotate = k%l;
        int nodeAT = l-rotate;

        if(rotate){
            p->next = head; //p points to the last node.

            p = head;
            for(int i=0; i<(nodeAT-1); i++) p = p->next;
            cout << p->val << " " << nodeAT;
            head = p->next;
            p->next = NULL;
        }

        return head;
    }
};