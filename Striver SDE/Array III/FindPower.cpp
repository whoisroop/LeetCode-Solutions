// LeetCode - 50. Pow (X, N).

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double getPower(double &x, int n){
        if(n==0) return 1;
        
        double power = getPower(x, n/2);
        if(n%2==0) return power*power;
        else return x*power*power;
    }
    
    double myPow(double x, int n) {
        int N = abs(n);
        double power = getPower(x, N);
        
        if(n>=0) return power;
        else return (1/power);
    }
};