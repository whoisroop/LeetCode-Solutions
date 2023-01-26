#include<bits/stdc++.h>
using namespace std;

// GCD(a, b) x LCM(a, b) = a x b

// EUCLIDEAN Method:
// GCD(a, b) = GCD(b, a MOD b)
// a % b = a - Kb, K = floor(a/b) : where a - Kb is largest positive integer to get the overall a - Kb to be the smallest positive value.
// a % b = (a - Kb) <-- is also divisible by the GCD(a, b)
// To utilize the result to find the GCD: GCD(a, b) = GCD(b, a MOD b). Where, b < a so that a MOD b approaches 0 at some instant and GCD ( X, 0 ) = X.

class Solution{
public:
    int GCD(int a, int b){
        if(b == 0) return a;
        
        return GCD(b, a%b);
    }

    int LCM(int a, int b){
        return ((1LL*a*b)/GCD(a, b));
    }
};

int main(){
    Solution find;
    int a, b;
    cout << "Enter A = ";
    cin >> a;

    cout << "Enter B = ";
    cin >> b;

    cout << "GCD: " << find.GCD(a, b) << endl;
    cout << "LCM: " << find.LCM(a, b) << endl;
    return 0;
}