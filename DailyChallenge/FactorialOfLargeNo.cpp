// GFG - Factorials Of Large Numbers.
// Description - 

// Store the digit in a vector and use the basic standard multiplication technique to modify the vector after multiplication.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void multiply(int value, vector<int> &digit){
        int carry = 0;
        for(int &i: digit){
            int x = value * i + carry;
            i = x % 10;
            carry = x/10;
        }
        
        while(carry != 0){
            digit.push_back(carry % 10);
            carry /= 10;
        }
    }
public:
    vector<int> factorial(int N){
        vector<int> digits;
        int value = N;
        while(value){
            digits.push_back(value % 10);
            value /= 10;
        }
        
        for(int i=2; i<N; i++) multiply(i, digits);
        
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

int main(){
    Solution solve;
    
    return 0;
}