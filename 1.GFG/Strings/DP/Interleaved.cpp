// Problem - Interleaved Strings
// Link - https://practice.geeksforgeeks.org/problems/interleaved-strings/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Description - Given strings A, B, and C, find whether C is formed by an interleaving of A and B.

// Approach:
// Match C[ic] to either A[ic] or B[ic] ... 
// Try all the possible combinations to find if there exists a case where entire string A & B are a subsequence of C.

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool match(int ia, int ib, int ic, string &A, string &B, string &C, vector<vector<int>> &DP){
        int N = A.size(); int M = B.size();
        int size = C.size();
        if(ic == size) return true;
        
        if(DP[ia][ib] != -1) return DP[ia][ib];
        bool X = false, Y = false;
        if(ia < N && A[ia] == C[ic]) X = match(ia+1, ib, ic+1, A, B, C, DP);
        if(X == true) return DP[ia][ib] = true;
        
        if(ib < M && B[ib] == C[ic]) Y = match(ia, ib+1, ic+1, A, B, C, DP);
        if(Y == true) return DP[ia][ib] = true;
        
        return DP[ia][ib] = false;
    }

public:
    bool isInterleave(string A, string B, string C) {
        vector<vector<int>> DP(A.size()+1, vector<int>(B.size()+1, -1));
        return match(0, 0, 0, A, B, C, DP);
    }
};

int main(){
    Solution solve;
    
    return 0;
}