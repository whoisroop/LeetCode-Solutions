// LeetCode - 206. Reverse Linked List.
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

class Solution{
private:
    void reverse(ListNode * pNode, ListNode * cNode, ListNode * &tail){  //Previous Node | Current Node | Tail (New Head Pointer)
        if(cNode == NULL){
            tail = pNode;
            return;
        }

        reverse(cNode, cNode->next, tail);
        // While returning, the pointers to previous node & current node remains stored in the stack space.
        cNode->next = pNode;
        return;
    }

public:
    ListNode * reverseList(ListNode * head){
        ListNode * tail = NULL;

        reverse(NULL, head, tail);
        // Tail & Head are reversed for the reverse case.
        return tail;
    }
};