// Problem - Longest Increasing Subsequence. 
// Link - https://practice.geeksforgeeks.org/problems/7d0fa4007b8eabadc404fcc9fa917aa52982aa96/1
// Description - N Students of different heights are attending an assembly. The heights of the students are represented by an array H[]. The problem is that if a student has less or equal height than the student standing in front of him, then he/she cannot see the assembly. Find the minimum number of students to be removed such that all the remaining students can see the assembly.

// Approach:
// We need to find the length of longest increasing subsequence & not the subsequence itself, it can be done in O(NlogN).
// 3 1 2 4 7 6

// 3
// 1 2
// 3 4 & 1 2 4
// What we can do is to overwrite the sequence on over another:
// 3 --> FOR 1 - Find upper bound of 1 & replace it with the value.
// 1 --> FOR 2 - Find upper bound of 2 & replace it with the value.
// 1 2 --> FOR 4 - Find upper bound of 4 & replace it with the value. 
// The value greater than 3 increments the 1st increasing subsequence, when we overwrite it with 1, the elements greater then 1 can be added to the increasing subsequence : PROVIDES OPTIMAL ANSWER.

#include<bits/stdc++.h>
using namespace std;

// LIS:
class Solution {
public:
    int removeStudents(int H[], int N) {
        vector<int> A(N, INT32_MAX);
        for(int i=0; i<N; i++){
            int index = (lower_bound(A.begin(), A.end(), H[i]) - A.begin());
            A[index] = H[i];
        }
        
        int counter = 0;
        while(counter < N && A[counter] != INT32_MAX) counter += 1;
        return (N-counter);
    }
};

int main(){
    Solution solve;
    
    return 0;
}