#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes){
        //All the primes factors are in vector primes.
        //Define index pointer for all the primes.
        vector<int> array(n, 0);
        array[0]=1; //First ugly number.
        int nPrimes = primes.size();
        vector<int> index(nPrimes, 0);    //All the pointers points to index 0 of array = 1.

        for(int i=1; i<n; i++){
            int mini = INT32_MAX;
            //Find the next minimum allowed multiple.
            //For prime[j] = A, the next multiplier array[index[j]] = array[indexA].    For simplicity.
            for(int j=0; j<nPrimes; j++){
                mini = min(1LL*mini, 1LL*primes[j]*array[index[j]]);    
            }

            for(int j=0; j<nPrimes; j++){
                if(1LL*mini == 1LL*primes[j]*array[index[j]])    index[j]++;
            }

            array[i] = mini;
        }

        return array[n-1];
    }

};

int main(){
    vector<int> primes = {2,7,13,19};
    int n = 12;
    Solution newSol;
    cout << newSol.nthSuperUglyNumber(n, primes);
    return 0;
}