// Problem - Smallest Distinct Window
// Link - https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1?page=1&category[]=two-pointer-algorithm&category[]=sliding-window&sprint=be405234ce3b8fcb54ed98f582862999&sortBy=submissions 
// Description - Given a string A. The task is to find the smallest window length that contains all the characters of the given string at least one time.

// Approach: When the distinct elements in the window equals K, store it as a candidate for the answer & decrement the window size trying to find the minimum size window which satisfies the condition.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findSubString(string A){
        int N = A.size();
        unordered_map<char, int> distinct; for(int i=0; i<N; i++) distinct[A[i]] += 1;
        int K = distinct.size();
        
        unordered_map<char, int> F;
        int i=0, j=0; int minL = INT32_MAX;
        while(j < N){
            F[A[j]] += 1;
            
            while(i <= j && F.size() == K){
                minL = min(minL, (j-i+1));
                F[A[i]] -= 1; if(F[A[i]] == 0) F.erase(A[i]);
                i += 1;
            }
            
            j += 1;
        }
        
        return minL;
    }
};

int main(){
    Solution solve;
    
    return 0;
}