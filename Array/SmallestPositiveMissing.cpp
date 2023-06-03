// GFG - Smallest positive missing number.
// Description - You are given an array A[] of N integers including 0. The task is to find the smallest positive number missing from the array.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int A[], int N) { 
        // [1 2 ... N] : The solution set.
        // To eliminate the space complexity, store the information in the given array:
        // Remove the negative values from array and mark the values that are present : < 0
        // Example: 1 2 4
        // 1: Present, if(A[1 - 1] > 0) A[1 - 1] = A[1 - 1] * (-1)
        // 2: Present, if(A[2 - 1] > 0) A[2 - 1] = A[2 - 1] * (-1)
        // 4: Present, if(A[4 - 1] > 0) A[4 - 1] = A[4 - 1] * (-1) OUT OF BOUND
        // ARRAY: -1 -2 4
        // Traverse: Index 2: Value 3 - Not Present
        // Max value: N + 1
        int maxmax = N+1;
        
        for(int i=0; i<N; i++) if(A[i] <= 0) A[i] = maxmax;
        for(int i=0; i<N; i++){
            int index = abs(A[i]) - 1;
            if((index < N) && (A[index] > 0)) A[index] *= -1;
        }
        
        for(int i=0; i<N; i++) if(A[i] > 0) return (i+1);
        
        return N+1;
    } 
};

int main(){
    Solution solve;
    
    return 0;
}