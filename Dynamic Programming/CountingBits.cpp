#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int findSetBits(int n){ //Find number of 1's in binary of equivalent of value n.
        int count = 0;
        for(int i=0; i<32; i++){
            if(((1 << i) & n) != 0) count++;
        }
        return count;
    }

public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1, 0);
        for(int i=1; i<=n; i++){
            bits[i] = findSetBits(i);
        }
        
        return bits;
    }
};

int main(){
    Solution newSol;
    vector<int> setBits = newSol.countBits(5);
    for(int i: setBits) cout << i << " ";
    return 0;
}