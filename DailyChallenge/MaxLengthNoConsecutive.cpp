// GFG - Find Maximum Length.
// Description - Given the maximum occurrences of a, b, and c in a string. Your task is to make the string containing only a, b, and c such that no three consecutive characters are the same. If the resultant string equals to a+b+c, return the length (a+b+c) otherwise -1.

// Approach:
// Use the max allowed consecutive of the max frequency element at all the time & then use a single instance of the next greater frequency element: USE PRIORITY QUEUE.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int a, int b, int c) {
        if(a+b+c <= 6) return (a+b+c);
        
        priority_queue<int> pq;
        pq.push(a); pq.push(b); pq.push(c);
        
        while(pq.size() > 1){
            int maxF = pq.top(); pq.pop();
            int nextF = pq.top(); pq.pop();
            
            maxF -= 2;
            nextF -= 1;
            if(maxF > 0) pq.push(maxF);
            if(nextF > 0) pq.push(nextF);
        }
        
        if((pq.size() == 0) || (pq.top() < 3)) return (a+b+c);
        return -1;
    }
};

int main(){
    Solution solve;
    
    return 0;
}