// GFG - Rearrange Array Alternately.
// Description - Given a sorted array of positive integers. Your task is to rearrange the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.
// Note: Modify the original array itself. Do it without using any extra space.

// Approach:
// Store two values at one position using the property of modulus:
// 1 2 3 4 5
// (1,5) (2,4) (3) : Store at the first half indexes.
// (1,5) (2,4) (3) | 4 5
// (1,5) ( - ) (2,4) ( - ) (3) : Rearrange
// (5) (1) (4) (2) (3) : Decode

// Max Value: Max(Array) + 1
// 1 2 3 4 5 : Max Value = 6
// A[i] = A[i] + A[j]*MAXVALUE
// Now 1 + 5*6, 2 + 4*6, 3 + 3*6
// Take MOD(MAXVALUE): 1 2 3
// Divide MAXVALUE: 5 4 3

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void rearrange(long long *A, int n) { 
        // EDGE CASES:
        if(n == 1) return;
        if(n == 2){
            A[0] = A[0] + A[1];
            A[1] = A[0] - A[1];
            A[0] = A[0] - A[1];
            
            return;
        }
        
        // Find Max:
        long long int maxV = A[n - 1] + 1;
        
        // Store two values in single element:
        for(int i=0; i<(n+1)/2; i++) A[i] = A[i] + maxV * A[(n-1) - i];
        
        // for(int i=0; i<(n+1)/2; i++) cout << A[i] << " : " << A[i]%maxV << " & " << A[i]/maxV << endl;
        
        int i = ((n+1)/2) - 1, j = (n-2);   // i: Middle Element & j : Last Second Element
        
        if(n%2 != 0){
            A[j + 1] = A[i]%maxV;
            i -= 1; j-= 1; 
        }
        
    	while(i<=j){
    	    A[j] = A[i];
    	    A[j+1] = A[j]%maxV;
    	    A[j] = A[j]/maxV;
    	    i-=1; j-=2;
    	}
    	
    	return;
    }
};

int main(){
    Solution solve;
    
    return 0;
}