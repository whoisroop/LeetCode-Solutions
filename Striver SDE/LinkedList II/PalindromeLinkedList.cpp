// LeetCode - 234. Palindrome Linked List.

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
    // Reversing LinkedList Solution:

    ListNode * reverse(ListNode * start){
        ListNode * pNode = NULL, * cNode = start, * nNode = start->next;
        while(cNode != NULL){
            nNode = cNode->next;
            cNode->next = pNode;
            pNode = cNode;
            cNode = nNode;
        }

        return pNode;
    }

    bool checkPalindrome(ListNode * pA){
        ListNode * slow = pA, * fast = pA;

        ListNode * previous = NULL;
        while(fast!=NULL && fast->next!=NULL){
            previous = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(slow == fast) return true;   //Length : 1

        // Odd:
        if(fast != NULL) previous = previous->next; //Slow Pointer

        previous->next = reverse(previous->next);
        
        previous = previous->next;
        while(previous!=NULL){
            if(pA->val != previous->val) return false;
            previous = previous->next;
            pA = pA->next;
        }

        return true;
    }

    // Using Stack:
    // Time & Space: O(N)
    bool isPalindrome(ListNode* head) {
        ListNode * slow = head, * fast = head;
        stack<int> stk;
        int length = 0;
        
        while(fast!=NULL && fast->next!=NULL){
            length++;
            stk.push(slow->val);
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //For even number of elements: fast will point at NULL.
        //For odd number of elements: fast will point at Last Element.
        if(fast == NULL) length = length * 2;
        else length = length*2 + 1;        
        
        if(length%2!=0) slow = slow->next;
        
        while(slow!=NULL){
            if(slow->val != stk.top()) return false;
            slow = slow->next;
            stk.pop();
        }
        
        return true;
    }
};