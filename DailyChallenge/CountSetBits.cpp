//GFG: Count Set Bits
//Description: 
//Approach:
// Identify the pattern:
// N = 6:
// 000 001 010 011 100 | 101 110 

// 0 0 0    (0)
// 0 0 1    (1)
// 0 1 0    (2)
// 0 1 1    (3)

// 1 0 0    (4)
// -----
// 1 2 2 : Set Bits
// Number of set bits for 1 to 4: 1 + (4/2) + (4/2)
// Where 4 is of the form 2^n
// The number greater than 2^2 and less than 2^3 will have the MSB digit set which is 2^2

// 1 0 1
// 1 1 0
// -----
// 2 1 1
// Number of set bits: MSB = (N - (1 << digits)) or (6 - 4) = 2
// And now find the number of set bits for 0 1 & 1 0 : (N - (1 << digits)) = 2 
// (1 ... N = 2)

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int bitcount(int N){
        if(N == 0) return 0;
        int n = ((1.0*log(N))/log(2)) + 1;  // n: 2^n the bit position is n+1.
        int value = 1 << (n-1);
        
        int counter = (value/2) * (n-1) + (N - value + 1) + bitcount(N-value);
        
        return counter;
    }

    // Count number of set bits in 1 2 ... N:
    int countSetBits(int N){
        return bitcount(N);
    }
};

int main(){
    Solution solve;
    
    return 0;
}