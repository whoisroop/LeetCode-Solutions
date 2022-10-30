// LeetCode - 142. Linked List Cycle II.

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
    bool hasCycle(ListNode * pA) {
        unordered_set<ListNode *> set;
        
        while(pA!=NULL){
            if(set.find(pA)!=set.end()) return pA;
            
            set.insert(pA);
            pA = pA->next;
        }
        
        return NULL;
    }
};