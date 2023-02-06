#include<bits/stdc++.h>
using namespace std;

// Return prime factorization of a number n using sieve of eratosthenes method. 
// Precomputation technique O(nlog(log(n))) ~ O(n)  

class Solution{
public:
    vector<int> prime_factorize(int n){
        vector<int> spf(n+1, 0);  //Smallest Prime Factor

        for(int i=2; i<=n; i++){
            // If the integer is not visited yet, it is prime.
            if(!spf[i]){
                for(int j=i; j<=n; j+=i){
                    if(!spf[j]) spf[j] = i;
                }
            }
        }

        cout << "SIEVE Vector: " << endl;
        for(int i: spf) cout << i << " ";

        vector<int> factors;
        while(spf[n] != n){
            factors.push_back(spf[n]);
            n = (n/spf[n]);
        } factors.push_back(spf[n]);

        cout << "\nPrime Factorization: " << endl;
        for(int i: factors) cout << i << " ";

        return factors;
    }
};

int main(){
    Solution factor;
    vector<int> pf = factor.prime_factorize(12);
    return 0;
}