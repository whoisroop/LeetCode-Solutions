// LeetCode - 141. Linked List Cycle.

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
    //Using SET:
    bool hasCycle(ListNode * pA) {
        unordered_set<ListNode *> set;
        
        while(pA!=NULL){
            if(set.find(pA)!=set.end()) return true;
            
            set.insert(pA);
            pA = pA->next;
        }
        
        return false;
    }

    //Using Slow & Fast Pointers:
    bool checkCycle(ListNode * pA) {
        ListNode * slow = pA, * fast = pA;
        
        while(fast!=NULL && fast->next!=NULL){
            if(fast == slow) return true;

            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false;
    }
};