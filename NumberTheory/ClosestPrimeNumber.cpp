// LeetCode: 2523. Closest Prime Numbers in Range.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> closestPrimes(int a, int b) {
        vector<int> primes(2, -1);

        int n = b;
        if(n <= 2) return primes;
        a = max(2, a);

        vector<int> sieve(b+1, 0);

        for(int i=2; i<=n; i++){
            if(!sieve[i]){
                for(int j=2*i; j<=n; j+=i){
                    sieve[j] = 1;
                }
            }
        }

        // cout << "SIEVE: ";
        // for(int i: sieve) cout << i << " ";

        int mini = INT32_MAX;
        int i = 0;
        for(int p = a; p<=n; p++) if(sieve[p]==0){ i = p; break; }
        
        int j = i + 1;
        while(j <= n){
            if(sieve[j]==0){
                if((j-i) < mini){
                    mini = (j-i);
                    primes = {i, j};
                }

                i = j; j = i+1;
            }

            j++;
        }

        cout << "\nPrimes: ";
        for(int i: primes) cout << i << " ";
        return primes;
    }
};

int main(){
    Solution find;
    find.closestPrimes(10, 20);
    return 0;
}