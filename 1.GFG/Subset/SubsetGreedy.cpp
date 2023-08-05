// Problem - Tricky Subset Problem
// Link - https://practice.geeksforgeeks.org/problems/tricky-subset-problem1557/1

// We can perform a greedy selection to get the target value when the array follows the given condition:
// A[0] + A[1] + .. A[i - 1] < A[i]
// Moving from right to left, if the element <= target then selecting the element is the optimal choice.
// As the value A[i] + some value = target, the A[i] part cannot be compensated by the left of the array even if we choose all the elements.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int isPossible(long long S, long long N, long long target, long long A[]){
        vector<long long int> sequence(N+1, 0);
        
        long long int tsum = S;
        int index = 0;
        sequence[0] = S;
        for(long long int i=0; i<N; i++){
            sequence[i+1] = (tsum + A[i]);
            tsum += (tsum + A[i]);
            
            if(tsum > target){ index = i+1; break; }
        }
        
        // Greedy:
        for(long long int i=index; (i>=0 && target>0); i--) if(sequence[i] <= target) target -= sequence[i];
        return (target == 0);
    }
};

int main(){
    Solution solve;
    
    return 0;
}