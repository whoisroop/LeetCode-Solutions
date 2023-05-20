// GFG : 3 Sum Closest.
// Description - Given an array A[] of N integers and an integer X. The task is to find the sum of three integers in A[] such that it is closest to X.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int closest3Sum(int A[], int N, int X){
        sort(A, A + N);
        int solution = 0;
        int difference = INT32_MAX;

        // A + B + C = 0
        // B + C = -A
        // All Triplets
        for(int i=0; i<N; i++){
            int tsum = X - A[i];
            int p = i+1, q = N-1;
            while(p<q){
                int sum = A[p] + A[q];
                if(abs(tsum - sum) < difference){
                    difference = abs(tsum - sum);
                    solution = (A[i] + A[p] + A[q]);
                }
                
                if(sum == tsum) return X;
                else if(sum < tsum) p += 1;
                else q -= 1;
                
            }
        }
        
        return solution;
    }
};
int main(){
    Solution solve;
    
    return 0;
}