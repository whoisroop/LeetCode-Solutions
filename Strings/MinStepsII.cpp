// GFG - Minimum steps to delete a string. 
// Link - https://practice.geeksforgeeks.org/problems/minimum-steps-to-delete-a-string2956/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Description - Given string A containing characters as integers only, the task is to delete all characters of this string in a minimum number of steps wherein one step you can delete the substring which is a palindrome. After deleting a substring remaining parts are concatenated.

// Approach:
// Refer minsteps one.
// We add an additional condition check, if the characters removed in the palindrome are consecutive the resulting string will be "" which doesn't contribute to the answer.

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int minstep(int i, int j, string &A, vector<vector<int>> &DP){
        if(i == j) return 1;
        if(i > j) return 0;
        
        if(DP[i][j] != -1) return DP[i][j];
        
        int steps = 1 + minstep(i+1, j, A, DP); //Remove A[i]
        
        // Example: AAB to remove A"_"A the resulting contained subtring will be "", B the value returned will be 0 & 1 respectively, incorrect.
        // We need: "_" - B = 1 + 1 The returned value. But, for cases: AB - A & B & "" = 1 + 1 + 1, incorrect.
        // As for removing cosecutive characters, nothing is contained in the substring, make a seperate case:
        int index = i+1; while(A[index] == A[i]) index += 1;
        steps = min(steps, 1 + minstep(index, j, A, DP));   //Remove A[i .. index], where A[i] = A[i+1] = ... = A[index]
        
        // Partition: A[i ... index] : DECOMPOSE - A[i+1 ... index-1] & A[index+1 ... j]
        // A[i] == A[index] FIND MINIMUM STEPS TO REDUCE SUBSTRING CONTAINED WITHIN.
        for(; index<=j; index++) if(A[index] == A[i]) steps = min(steps, minstep(i+1, index-1, A, DP) + minstep(index+1, j, A, DP));
        
        return DP[i][j] = steps;
    }
    
public:
	int minStepToDeleteString(string A){ 
	    int N = A.size();
	    vector<vector<int>> DP(N, vector<int>(N, -1));
	    return minstep(0, A.size()-1, A, DP);
	} 
};

int main(){
    Solution solve;
    
    return 0;
}