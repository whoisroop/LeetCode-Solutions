// GFG : Find MOD Of Big Number.
// Description - 

// Approach:
// (a+b)%m = ((a%m)+(b%m))%m
// (a-b)%m = ((a%m)-(b%m))%m
// (a*b)%m = ((a%m)*(b%m))%m

// (1 2 3 4) % 11
// (1 * 10^3 + 2 * 10^2 + 3 * 10^1 + 4 * 10^0) % 11
// 10^3 ( 1 + 2*10^-1 + 3*10^-2 + 4*10^-3) % 11
// 10^2 ( [1 * 10 + 2] + 3*10^-1 + 4*10^-2) % 11
// 10^2 (1*10 + 2) % 11 + 10^2 (3*10^-1 + 4*10^-2) % 11
// (10^2 % 11) x (R) + (10^2 % 11) x ((3*10^-1 + 4*10^-2) % 11)
// (10^2 (R + 3*10^-1 + 4*10^-2)) % 11
// 10^1 (R * 10 + 3 + 4*10^-1) % 11
// REPEAT:-


#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int xmod11(string x, int m){
       int modV = 0;
       int n = x.size();
       for(int i=0; i<n; i++) modV = ((modV * 10) + int(x[i] - '0')) % m;
       
       return modV;
    }
};

int main(){
    Solution solve;
    
    return 0;
}