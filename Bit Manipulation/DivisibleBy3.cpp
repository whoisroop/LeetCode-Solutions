// GFG - Is Binary Number Multiple of 3.
// Description - Given a binary number, Find, if given binary number is a multiple of 3. The given number can be big upto 2^10000. It is recommended to finish the task using one traversal of input binary string.

// Approach:
// Let the binary number be of form: abcde
// Convert to decimal: a*2^4 + b*2^3 + c*2^2 + d*2^1 + e*2^0
// (16 * a) + (8 * b) + (4 * c) + (2 * d) + (1 * e)
// 2^n can be represented in the form (3n + 1) for even value of n and (3n - 1) for odd value of n:
// (3*5 + 1)*a + (3*3 - 1)*b + (3*1 + 1)*c + (3*1 - 1)*d + (3*0 + 1)*e
// (a + c + e) + (15 * a) + (3 * c) - (b + d) + (9 * b) + (3 * d)
// (a + c + e) - (b + d) + 3 * (5*a + 1*c + 3*b + 1*d)
// (a + c + e) - (b + d) + 3 * N
// The divisibility depends on the values of a, b, c, d, e where a, b, c, d, e are binary 0 or 1.
// If (a + c + e) - (b + d) : (SUM OF EVEN PLACES) - (SUM OF ODD PLACES) = 3 * M form, the binary number is divisible by 3. 

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int isDivisible(string A){
	    int n = A.size();
	    int even = 0, odd = 0;
	    for(int i=0; i<n; i++){
	        if(A[i] == '1'){
	            if(i%2 == 0) even += 1;
	            else odd += 1;
	        }
	    }
	    
	    if((even - odd)%3 == 0) return 1;
	    else return 0;
	}
};

int main(){
    Solution solve;
    
    return 0;
}