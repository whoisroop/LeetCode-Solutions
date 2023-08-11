// LeetCode: 
// Description: 
// Approach: 

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
public:
    int countgood(string A){
        int N = A.size();
        vector<int> F(26, 0);
        for(int i=0; i<N; i++) F[A[i] - 'a'] += 1;

        int MOD = 1e9 + 7;
        long long int counter = 1;
        for(int i=0; i<26; i++) if(F[i] > 0){ counter = counter * F[i]; counter %= MOD; }

        cout << counter << endl;
        return counter;
    }
};

int main(){
    Solution solve;
    solve.countgood("abca");
    return 0;
}