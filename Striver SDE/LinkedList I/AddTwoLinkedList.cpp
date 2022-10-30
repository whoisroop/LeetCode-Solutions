// LeetCode - 2. Add Two Numbers.
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

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

class Solution{
public:
    ListNode * addLinkedList(ListNode * pA, ListNode * pB){
        ListNode * list = new ListNode();
        ListNode * pC = list;
        
        int carry = 0;

        // pA: Pointer To List A.
        while(pA!=NULL || pB!=NULL || carry){
            int sum = carry;
            if(pA) sum += pA->val;
            if(pB) sum += pB->val;
            carry = sum/10;
            
            ListNode * newNode = new ListNode((sum%10), NULL);
            pC->next = newNode;

            if(pA) pA = pA->next;
            if(pB) pB = pB->next;
            pC = pC->next;
        }

        return (list->next);
    }
};

    // Initital Implementation -
     
        // while(pA!=NULL){
        //     int sum = pA->val + carry;
        //     carry = sum/10;
            
        //     ListNode * newNode = new ListNode((sum%10), NULL);
        //     pC->next = newNode;

        //     pA = pA->next;
        //     pC = pC->next;
        // }

        // while(pB!=NULL){
        //     int sum = pB->val + carry;
        //     carry = sum/10;
            
        //     ListNode * newNode = new ListNode((sum%10), NULL);
        //     pC->next = newNode;

        //     pB = pB->next;
        //     pC = pC->next;
        // }

        // if(carry != 0){
        //     int sum = carry;
        //     carry = sum/10;
            
        //     ListNode * newNode = new ListNode((sum%10), NULL);
        //     pC->next = newNode;
        // }