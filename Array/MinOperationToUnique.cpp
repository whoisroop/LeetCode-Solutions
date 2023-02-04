// LeetCode - 945. Minimum Increment to Make Array Unique
// Description - 
// You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
// Return the minimum number of moves to make every value in nums unique.
// The test cases are generated so that the answer fits in a 32-bit integer.

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:

public:
    int minIncrementForUnique(vector<int> &A) {
        int n = A.size();
        if(n == 1) return 0;

        sort(A.begin(), A.end());

        int increment = 0;
        for(int i = 1; i<n; i++){
            if(A[i] <= A[i-1]){
                increment += ((A[i-1] + 1) - A[i]);
                A[i] = (A[i-1] + 1);
            }
        }

        return increment;
    }
};

int main(){
    Solution solve;
    
    return 0;
}