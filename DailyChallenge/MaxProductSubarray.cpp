// LeetCode -
// Description - Find The Max Sub-Array Product

// Approach:
// Either you can carry foward the previous product i.e. continue the product subarray product.
// Or you can start a new product starting from the current element.
// Multiplication with negative makes the biggest number the smallest.


#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long max(long long a, long long b){
        if(a > b) return a;
        else return b;
    }
    
    long long min(long long a, long long b){
        if(a > b) return b;
        else return a;
    }

	// Function to find maximum product subarray
	long long maxProduct(vector<int> A, int n) {
	    long long maxproduct = A[0];
	    
	    long long max_p = 1, min_p = 1;
	    for(int i=0; i<n; i++){
	        if(A[i] == 0){ max_p = 1; min_p = 1; continue; }
	        
	        if(A[i] < 0) swap(max_p, min_p);
	        max_p = max(A[i], max_p * A[i]);
	        min_p = min(A[i], min_p * A[i]);
	        
	        maxproduct = max(maxproduct, max_p);
	    }
	    
	    return maxproduct;
	}
};

int main(){
    Solution solve;
    
    return 0;
}