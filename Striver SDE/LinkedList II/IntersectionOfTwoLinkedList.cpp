// LeetCode - 160. Intersection Of Two Linked List.

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

class Solution {
public:
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
        if(headA==NULL || headB==NULL) return NULL;
        
        ListNode * startA = new ListNode(0, headA);
        ListNode * startB = new ListNode(0, headB);
        ListNode * pA = startA, * pB = startB;
        int la=-1, lb=-1; //Length Of A & B
        
        while(pA!=NULL){
            la++;
            pA = pA->next;
        }
        
        while(pB!=NULL){
            lb++;
            pB = pB->next;
        }
        
        // Reset Pointers:
        pA = startA; pB = startB;
        
        if(la >= lb){
            for(int i=0; i<(la-lb); i++){ pA = pA->next; }
        }
        else{
            for(int i=0; i<(lb-la); i++){ pB = pB->next; }
        }
        
        while(pA!=NULL && pB!=NULL){
            if(pA == pB) return pA;
            pA = pA->next;
            pB = pB->next;
        }
        
        return NULL;
        
    }

    // Another Smart Approach:
    ListNode * findIntersectionNode(ListNode * headA, ListNode * headB) {
        if(headA==NULL || headB==NULL) return NULL;
        
        ListNode * startA = new ListNode(0, headA);
        ListNode * startB = new ListNode(0, headB);
        ListNode * pA = startA, * pB = startB;
        
        //Difference is in how we gap the difference:
        //The shorter list will exhaust first: Point its pointer to the start of other list.
        //Till the time longer list is exhausted, the pointer which points to the longer list will bridge the gap or difference.
        //When the longer list will: Point its pointer to the start of other list.
        //Now both pointer are at a same distance from the END node (as well as from intersection node).
        
        while(pA != pB){
            if(pA == NULL) pA = startB;
            if(pB == NULL) pB = startA;
            pA = pA->next;
            pB = pB->next;
        }
        
        return pA;
    }
};