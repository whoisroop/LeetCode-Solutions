// LeetCode - 155. Min Stack.

// Approach:
// How to know which data structure to use to implement? 
// Like even for max sum problem how/why the monotonic stack will hit out mind? Or in the case of LRU?
// In such questions where we need to maintain some order to keep track of max or min:
// Draw a doubly linked list & keep adding/removing/rearranging previously added or newly added elements. Find out which elements are relevant & which ones are not for finding the required output.

// For the current example: 
// We need to maintain an order of candidates for the minimum value in the stack:
// Inputs - A = {-2, 0, -3}
// -2: -2   (Minimum: Either at front or back)
// 0: -2 0  (0 is the next cadidate for minimum after -2) : But do we need really require 0? The stack will be popped from back & 0 will be popped first, even when 0 is present or not the minimum in both cases are -2. Hence 0 is irrelevant in the ordering --> Any value greater than the front of list is irrelevant so do not add to the ordering list.
// LIST = -2
// -3: -2 -3 (-3 becomes the top candidate)
// A = {-2, 0, -3} LIST = {-2 -3} MINIMUM = LIST.BACK() = -3
// POP(A) : A = {-2, 0} List = -2 (BACK = -2) The popped element is not a candidate. If(Popped Element = Back Of List) Remove Back Of List.
// POP(A) = {-2} List = -2 (BACK = -2) 

#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> stk;
    stack<int> mini;
    
    MinStack() {
        
    }
    
    void push(int value) {
        stk.push(value);
        if(mini.empty() || value <= mini.top()) mini.push(value);
    }
    
    void pop() {
        if(stk.top() == mini.top()) mini.pop();
        stk.pop();
    }
    
    int top() {
        if(!stk.empty()) return stk.top();
        return -1;
    }
    
    int getMin() {
        if(!mini.empty()) return mini.top();
        return -1;
    }
};