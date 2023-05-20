// GFG - Sorting Elements of an Array by Frequency.
// Description - Given an array of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

#include<bits/stdc++.h>
using namespace std;

int modv = 100001;

bool comparator(int &a, int &b){
    if((a/modv) == (b/modv)) return ((a%modv) < (b%modv));
    return ((a/modv) > (b/modv));
}

class Solution{
    public:
    vector<int> sortByFreq(int given[], int N){
        unordered_map<int, int> fmap;
        for(int i=0; i<N; i++) fmap[given[i]] += 1;
        
        vector<int> A(N, 0);
        for(int i=0; i<N; i++) A[i] = given[i] + fmap[given[i]] * modv;
        
        sort(A.begin(), A.end(), comparator);
        for(int i=0; i<N; i++) A[i] = A[i] % modv;
        
        return A;
    }
};

int main(){
    Solution solve;
    
    return 0;
}