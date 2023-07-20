#include<bits/stdc++.h>
using namespace std;

// Problem - Longest Common Substring: 
// Description - Given two strings. The task is to find the length of the longest common substring.

// Approach:
// Same approach as the longest common subsequence, with a little modification:
// If A[ia] == B[ib] :  DP[ia+1][ib+1] = DP[ia][ib] + 1; Check the length of longest substring till (ia-1, ib-1) & increment the length.
// Compare & increment the length of consecutive matched characters of string A & string B.
// If A[ia] != B[ib] : DP[ia+1][ib+1] = 0;

class Solution{
public:
    int longestCommonSubstr(string A, string B, int N, int M){
        vector<vector<int>> DP(N+1, vector<int>(M+1, 0));
        
        int maxV = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(A[i] == B[j]) DP[i+1][j+1] = DP[i][j] + 1;
                else DP[i+1][j+1] = 0;
                
                maxV = max(maxV, DP[i+1][j+1]);
            }
        }
        
        return maxV;
    }
};

// Problem: Longest repeating and non-overlapping substring:
// Link: https://practice.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring3421/1
// Example: "ablhiabohi". Here both "ab" and "hi" are possible answers. But you will have to return "ab" as because it repeats before "hi".

// Approach:
// Let: ABBBA - How to avoid the BB case? Even by adding the condition (ia!=ib) will not eliminate. (B:0 B:1 & B:1 B:2) ?
// Only add to the solution after checking overlapping:
// A(BB)BA AB(BB)A
// 0 12 34 01 23 4
// ia = 2, ib = 3, L = 1 ( + 1 Pending Update)
// Check (ib - L > ia) - NO OVERLAP
// CONDITION (ib - ia > L)

class Solution {
public:
    string longestSubstring(string A, int N) {
        string B = A;
        vector<vector<int>> DP(N+1, vector<int>(N+1, 0));
        
        int maxV = 0; vector<int> index(2, -1);
        for(int ia=0; ia<N; ia++){
            for(int ib=0; ib<N; ib++){
                if(A[ia] == B[ib] && (ib - ia) > DP[ia][ib]) DP[ia+1][ib+1] = DP[ia][ib] + 1;
                else DP[ia+1][ib+1] = 0;
                
                if(DP[ia+1][ib+1] > maxV){ index[0] = ia; index[1] = ib; maxV = DP[ia+1][ib+1]; }   //For Printing The String: Store Index & Back Track
            }
        }
        
        if(maxV == 0) return "-1";
        
        string solution = "";
        for(int i=0; i<maxV; i++){ solution += A[index[0] - i]; }
        reverse(solution.begin(), solution.end());
        
        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}