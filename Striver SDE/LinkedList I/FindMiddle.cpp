// LeetCode - 876. Find Middle Of Linked List.

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode{
    int val = 0;
    struct ListNode * next = NULL;

    ListNode(int aVal, struct ListNode * aNext){
        val = aVal;
        next = aNext;
    }
};

class Solution {
public:
    ListNode * middleNode(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        
        while(fast != NULL && fast->next != NULL){
            //Fast travels twice as fast as the slow.
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};