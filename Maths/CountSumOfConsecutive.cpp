// GFG - Count of sum of consecutives.
// Description - Given a number N, the task is find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getCount(int value) {
        // Start: a, Elements: N+1
        // Value = a + (a+1) + (a+2) + ... + (a + N)
        // Value = ((N+1)*a) + ((N)*(N+1))/2
        // Value = (N+1)(a + N/2)
        // (Value/(N+1) - N/2) = a
        // Value : KNOWN ; Choose N such that a is an integer > 0.
        
        // 1 + 2 + ... will be the largest chain: (n)*(n+1)/2 = value
        // (n+1)*(n+1)/2 > value
        // (n+1)^2 > 2 * value
        // n+1 > sqrt(2*value)
        // n > (sqrt(2*value) - 1)
        // n = sqrt(2*value)
        int maxN = (sqrt(2 * value)); 
        
        // a = (value/(N+1) - N/2)
        int N = 1;  //Elements: N + 1
        
        int counter = 0;
        double start = 0;
        for(int N=1; N<maxN; N++){
            start = (((1.0*value)/(N+1)) - ((1.0*N)/2));
            
            if(start > 0 && start == int(start)) counter += 1;
        }
        
        return counter;
    }
};

int main(){
    Solution solve;
    
    return 0;
}