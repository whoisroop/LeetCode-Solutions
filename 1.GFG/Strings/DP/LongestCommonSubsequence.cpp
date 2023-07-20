#include<bits/stdc++.h>
using namespace std;

// * Problem - Longest Common Subsequence:
// Link - 

// Compare the ia index of string A with ib index of string B:
// If same: Increment the length of longest subsequence. DP[ia+1][ib+1] = DP[ia][ib] + 1;
// If not: Carry forward the the of longest subsequence. DP[ia+1][ib+1] = max(DP[ia][ib+1], DP[ia+1][ib]);
// Draw the table for better understanding:

class Solution{
public:
    int LCS(string A, string B, int N, int M){
        vector<vector<int>> DP(N+1, vector<int>(M+1, 0));

        for(int ia=0; ia<N; ia++){
            for(int ib=0; ib<M; ib++){
                if(A[ia] == B[ib]) DP[ia+1][ib+1] = DP[ia][ib] + 1; //MATCH
                else DP[ia+1][ib+1] = max(DP[ia][ib+1], DP[ia+1][ib]);  //NOT MATCH
            }
        }
        
        return DP[N][M];
    }
};

// * Problem - Shortest Common Supersequence:
// Link - https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
// Description - Given two strings A and B of lengths N and M respectively, find the length of the smallest string which has both, A and B as its sub-sequences.

// Approach: Find LCS Of A & B: Doesn't need to repeat, appears only once in the supersequence.
// Let the common elements be - COMMON
// Size of shortest common subsequence : (N - COMMON) + (M - COMMON) + COMMON

class Solution{
public:
    int shortestCommonSupersequence(string A, string B, int N, int M){
        vector<vector<int>> DP(N+1, vector<int>(M+1, 0));
        
        int maxi = 0;
        for(int ia=0; ia<N; ia++){
            for(int ib=0; ib<M; ib++){
                if(A[ia] == B[ib]) DP[ia+1][ib+1] = DP[ia][ib] + 1;
                else DP[ia+1][ib+1] = max(DP[ia][ib+1], DP[ia+1][ib]);
            
                maxi = max(maxi, DP[ia+1][ib+1]);
            }
        }
        
        return ((N-maxi) + (M-maxi)) + maxi;
    }
};

// * Problem - Form A Palindrome:
// Link - https://practice.geeksforgeeks.org/problems/form-a-palindrome2544/1
// Description - Given a string, find the minimum number of characters to be inserted to convert it to palindrome.

// Approach: Find the LCS of string A & the reverse of string A.
// A palindome is the same in reverse, so preserve the characters that follows the property of palindrome.
// The solution will be N - LCS(A, REVERSE OF A)

class Solution{   
public:
    int findMinInsertions(string A){
        // LCS 
        int N = A.size();
        vector<vector<int>> DP(N+1, vector<int>(N+1, 0));
        
        string B = A; reverse(B.begin(), B.end());
        for(int ia=0; ia<N; ia++){
            for(int ib=0; ib<N; ib++){
                if(A[ia] == B[ib]) DP[ia+1][ib+1] = DP[ia][ib] + 1;
                else DP[ia+1][ib+1] = max(DP[ia][ib+1], DP[ia+1][ib]);
            }
        }
        
        return N - DP[N][N];
    }
};

// * Problem - Longest Palindromic Subsequence
// Link - https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
// Apporoach: FIND LCS of A & REVERSE OF A:

class Solution{
public:
    int longestPalinSubseq(string A) {
        int N = A.size();
        vector<vector<int>> DP(N+1, vector<int>(N+1, 0));
        
        string B = A; reverse(B.begin(), B.end());  //Find LCS(A, REVERSE OF A)

        for(int ia=0; ia<N; ia++){
            for(int ib=0; ib<N; ib++){
                if(A[ia] == B[ib]) DP[ia+1][ib+1] = DP[ia][ib] + 1;
                else DP[ia+1][ib+1] = max(DP[ia][ib+1], DP[ia+1][ib]);
            }
        }
        
        return DP[N][N];
    }
};

int main(){
    Solution solve;
    
    return 0;
}