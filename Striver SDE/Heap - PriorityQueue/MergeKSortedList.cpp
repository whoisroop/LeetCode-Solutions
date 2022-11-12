// LeetCode - 23. Merge K Sorted List.
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// Same concept as merging two sorted arrays.
// Use max heap to keep track of the indexes/nodes.

#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct compare{
  bool operator()(pair<int, ListNode *> &A, pair<int, ListNode *> &B){
      return A.first > B.first;
  }
};

class Solution {
public:
    ListNode * mergeKLists(vector<ListNode*> &L) {
        int n = L.size();
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, compare> minheap;   //<Value, <I, J>>
        ListNode * start = new ListNode();
        ListNode * px = start;
        
        for(int i=0; i<n; i++){
            if(L[i]!=NULL) minheap.push({L[i]->val , L[i]});
        }
        
        while(!minheap.empty()){
            ListNode * qx = minheap.top().second;
            int value = minheap.top().first;
            
            minheap.pop();
            
            if(qx!=NULL){
                px->next = qx; 
                px = px->next;
                if(qx->next != NULL) minheap.push({qx->next->val, qx->next});
            }
        }
        
        return (start->next);
    }
};