// Leetcode - 686. Repeated String Match.
// RABIN KARP Algorithm For String Matching.
// Convert the strings into equivalent hash code & use it for comparision. Use the sliding window technique for calculating the new hash code of the window and compare it with the target hash code.
// HASHING TECHNIQUE! How to avoid the collision in hashing, if hashing is poor then the complexity will rise to O(N*N).
// Polynomial Hashing Technique:
// Different Number System? What does it actually mean?
// Base: 2 - Represent two different values using single symbol. Base: 10 - Represent ten different values using single symbol. Base: 16 - Represent sixteen different values using single symbol.
// In total we have 256 characters defined in ASCII table. Use a number system with base value 256.


#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    const int BASE = 31;
    const int MOD = 1000001;
public:
    int RabinKarp(string source, string pattern){
        int nS = source.size();
        int nP = pattern.size();

        int tHash = 0; //Target Hash Or Pattern Hash
        for(int i=0; i<nP; i++) tHash = ((1LL*tHash)*BASE + pattern[i])%MOD;

        //Now Compare Using Sliding Window Technique:
        int power = 1; for(int i=0; i<(nP-1); i++) power = ((1LL*power)*BASE)%MOD; //Power of the first element in the window.
        int counter = 0;
        //Window Configuration:
        int i=0, j=0;
        int wHash = 0;  //Window Hash
        int wsize = nP; //Window Size
        while(j<nS){
            wHash = ((1LL*wHash)*BASE + source[j])%MOD;

            if((j-i+1)<wsize) { j++; continue; }
            // cout << i << " , " << j << " HASH: " << wHash << " VS " << tHash << endl;
            if(wHash == tHash){ //If window hash == target hash.
                bool match = true;
                for(int p=i; p<=j; p++){
                    if(source[p] != pattern[p-i]){ match=false; break; }
                }

                if(match) counter++;
            }

            // Remove The First Element From HASH!
            wHash -= ((1LL*source[i])*power)%MOD;
            if(wHash < 0) wHash += MOD;
            i++; j++;
        }

        return counter; //Number of occurence of pattern in the source.
    }
};

int main(){
    Solution find;
    string source = "abcdabcdabcd";
    string target = "cdabcdab";
    cout << find.RabinKarp(source, target);
    return 0;
}