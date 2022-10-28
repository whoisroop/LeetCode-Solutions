// LeetCode - 19. Remove Nth Node From End.
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
};

class Solution {
private:
    void remove(ListNode * pNode, ListNode * cNode, int &counter){
        if(cNode == NULL) return;
        
        remove(cNode, cNode->next, counter);
        counter--;
        if(counter == 0){
            pNode->next = cNode->next;
        }
        return;
    }

public:
    ListNode* removeNthFromEnd(ListNode* h, int n) {
        ListNode * head = new ListNode(0, h);

        remove(NULL, head, n);
        return (head->next);
    }
};

// Iterative One Pass Solution:
// Let's assign two pointers - fast and slow to head. We will first iterate for n nodes from start using the fast pointer.
// Now, between the fast and slow pointers, there is a gap of n nodes. Now, just Iterate and increment both the pointers till fast reaches the last node. The gap between fast and slow is still of n nodes, meaning that slow is nth node from the last node (which currently is fast).

// CODE:

//  ListNode* removeNthFromEnd(ListNode* head, int n) {
// 	    ListNode *fast = head, *slow = head;

// 	    while(n--) fast = fast -> next;      // Iterate first n nodes using fast

// 	    if(!fast) return head -> next;       // If fast is already null, it means we have to delete head itself. So, just return next of head

// 	    while(fast -> next){                 // Iterate till fast reaches the last node of list
// 		    fast = fast -> next, slow = slow -> next;
//      }

// 	    slow -> next = slow -> next -> next; // Remove the nth node from last
// 	    return head;
//  }