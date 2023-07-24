// LeetCode - 1680. Concatenation of Consecutive Binary Numbers.
//Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.
// Input: n = 3
// Output: 27
// Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
// After concatenating them, we have "11011", which corresponds to the decimal value 27.

#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

class Solution{
public:
    int concatenate(int n){
        long long int value = 0;
        
        int shift=0;
        for(int i=1; i<=n; i++){
            if((i&(i-1)) == 0) shift++;
            value = ((value<<shift) | (i));
        }

        bitset<32> x(value);
        cout << x << endl;
        cout << value;
        return 0;

    }
};

int main(){
    Solution find;
    find.concatenate(12);
    return 0;
}