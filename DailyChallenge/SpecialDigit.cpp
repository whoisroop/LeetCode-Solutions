// GFG: Special Digits.
// Description - You are given 5 integers - N,A,B,C,D.
// Let us say all the integers of length N, having only A or B in their decimal representation are good integers. Also, among all the good integers, all those integers whose sum of digits should contains either C or D or both on it, are best integers.
// Find the number of best integers of length N. Since the number of best integers can be huge, print it modulo 109+7.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int MOD = 1e9 + 7;
    
    int NCR(int N, int R){  // N!/(R! x (N-R)!)
        int value = 1;
        for(int i=1; i<=R; i++){
            value *= 1LL*(N - i + 1) / i;
        }
        
        return value;
    }
    
    int bestNumbers(int N, int A, int B, int C, int D) {
        unordered_map<int, int> fsum;
        for(int i=0; i<N; i++){
            int sum = (1LL*i * A + 1LL*(N - i) * B) % MOD;
            fsum[sum] = NCR(N, i); //Total possible permutations. A A B B B :- (5!)/(2!)(3!)
        }
        
        // Check if the sum value contains the digit:
        int counter = 0;
        for(auto &i: fsum){
            int digit = i.first;
            while(digit > 0){
                if(digit%10 == C || digit%10 == D){ counter += i.second; break; }
                digit = digit/10;
            }
        }
        
        return counter;
    }
};

int main(){
    Solution solve;
    
    return 0;
}