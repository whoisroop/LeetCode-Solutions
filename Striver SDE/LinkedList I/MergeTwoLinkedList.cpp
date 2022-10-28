// LeetCode - 21. Merge Two Sorted Linked List.

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
    ListNode* mergeTwoLists(ListNode* listA, ListNode* listB) {
        ListNode * head = new ListNode();
        
        ListNode * node = head;
        while(listA!=NULL && listB!=NULL){
            if(listA->val <= listB->val){
                node->next = listA;
                listA = listA->next;
            }
            else{
                node->next = listB;
                listB = listB->next;
            }
            
            node = node->next;
        }
        
        while(listA){
            node->next = listA;
            listA = listA->next;
            
            node = node->next;
        }
        while(listB){
            node->next = listB;
            listB = listB->next;
            
            node = node->next;
        }
        
        return (head->next);
    }
};