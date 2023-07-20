// LeetCode - 
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countDistinctSubarray(int A[], int N){
        unordered_map<int, int> distinct; for(int i=0; i<N; i++) distinct[A[i]] += 1;
        int K = distinct.size();
        
        unordered_map<int, int> F;
        int i=0, j=0; int counter = 0;
        while(j < N){
            F[A[j]] += 1;
            
            // Solution Acquired When Distinct Element == K
            // If A[i .. j] : K Distinct Elements, A[i .. j+1] A[i .. j+2] ... A[i .. N] will also have K distinct elements - Total Distinct Elements In The ARRAY = K
            // When solution found in the range [i .. j] try finding for the range [i+1 .. j] & so on...
            // If distict elements < K, include new elements.
            while(i <= j && F.size() == K){
                counter += (N - j);
                F[A[i]] -= 1; if(F[A[i]] == 0) F.erase(A[i]);
                i += 1;
            }
            
            
            j += 1;
        }
        
        return counter;
    }
};

int main(){
    Solution solve;
    
    return 0;
}