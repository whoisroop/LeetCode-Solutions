// Find Next Smaller Elements: Linear Array.

#include<bits/stdc++.h>
using namespace std;

// Refer Next Greater Element.

class Solution {
public:
    vector<int> nextSmallerElements(vector<int> &A) {
        int n = A.size();
        vector<int> nextsmall(n, -1);
        stack<int> stk;
        
        for(int i=(n-1); i>=0; i--){
            while(!stk.empty() && stk.top() >= A[i]) stk.pop();
            
            if(!stk.empty()) nextsmall[i] = stk.top();
            else nextsmall[i] = -1;
            
            stk.push(A[i]);
        }
        
        return nextsmall;
    }
};