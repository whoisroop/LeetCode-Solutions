// LeetCode - 237. Delete Node In Linked List.
// There is a singly-linked list head and we want to delete a node 'node' in it.
// You are given the node to be deleted node. You will not be given access to the first node of head.
// All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

// Approach:
// 1 2 3 (4) 5 6 (DELETE 4)
// 1) First Step: Shift the next node to current position by copying its value:
// 1 2 3 (5) 5 6
// 2) Second Step: Remove the next node: node->next = node->next->next;
// 1 2 3 5 5 6
//         ^
// Result: 1 2 3 5 6

#include<iostream>
#include<vector>
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

class Solution {
public:
    void deleteNode(ListNode * node) {
        node->val = node->next->val;    //Swap the values of current & next node.
        node->next = node ->next->next; //Delete the next node.
    }
};