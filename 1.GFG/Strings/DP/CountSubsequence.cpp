// Problem - Count subsequences of type a^i, b^j, c^k
// Link - https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck4425/1
// Description - Given a string S, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

// Approach:
// The ordering will be a - b - c:
// For last character 'a' the next choice can be either 'a' or 'b' 
// Similarly for last character 'b' the next choice can be either 'b' or 'c'
// i.e. when compared using ASCII values the choice will be: (value or value + 1)
// To indicate no choice is made: ('a' - 1) : Next element to be choosen i.e. start of a subsequence will be 'a'.
// Declare a DP with parameters: current index & last choosen character.
// MaxIndex = N & Max ASCII Value Of Choosen Character : 'a', 'b' or 'c' - (CHARACTER - 'a') = 3
// Normalize the characters, all the alphabetic characters will take 26 size. (0: 'a', 1: 'b', 2: 'c', ...)
// Count all the solutions, to check if the subsequence is of correct order, check the last choosen character. (SHOULD BE 'c')

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int MOD = 1e9 + 7;
    int count(int index, string &A, char previous, vector<vector<int>> &DP){
        int N = A.size();
        if(index == N) return previous == 'c';
        
        if(DP[index][previous - 'a' + 1] != -1) return DP[index][previous - 'a' + 1];
        
        long long int take = 0; int ntake = 0;

        // TAKE:
        if(A[index] == previous || A[index] == previous + 1) take = count(index+1, A, A[index], DP);
        // NOT TAKE:
        ntake = count(index+1, A, previous, DP);
        
        return DP[index][previous - 'a' + 1] = (take%MOD + ntake%MOD)%MOD;
}
    
public:
    int fun(string &A) {
        vector<vector<int>> DP(A.size()+1, vector<int>(26 + 1, -1));
        return count(0, A, ('a' - 1), DP);
    }
};

int main(){
    Solution solve;
    
    return 0;
}