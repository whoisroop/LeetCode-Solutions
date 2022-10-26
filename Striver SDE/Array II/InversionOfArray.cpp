// LeetCode - NA. Count Inversions.
// A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:
// 1. ARR[i] > ARR[j] 
// 2. i < j
// Where 'i' and 'j' denote the indices ranging from [0, 'N').

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countInversion(vector<int> &array){
        return 0;
    }
};

int main(){
    set<int> iset = {1, 5 , 3};
    iset.insert(2);
    for(int i: iset) cout << i << " ";


    return 0;
}