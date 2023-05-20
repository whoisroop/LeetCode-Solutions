// GFG: Count triplets with sum smaller than X.
// Description: 
// Approach: 
// A + B + C < T
// B + C < (T - A)

// A = 0 1 1 3 : tsum = 4
// If p index + q index < tsum : All the elements smaller than A[q] when coupled or added with A[p] will result into a smaller sum.
// Total such pairs: (p, q) (p, q-1) (p, q-2) ... (p, p+1) = (q-p)
// If p index + q index > tsum : Decrement q index.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	long long countTriplets(long long A[], int N, long long X){
	    sort(A, A + N);
	    long long int counter = 0;
	    for(int i=0; i<N; i++){
	        long long int tsum = X - A[i];
	        int p = i+1, q = N-1;
	        
	        while(p<q){
	            if(A[p] + A[q] < tsum){
	                counter += (q-p);
	                p += 1;
	            }
	            else q -= 1;
	        }
	    }
	    
	    return counter;
	}
};

int main(){
    Solution solve;
    
    return 0;
}