#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestIncreasingSubsequence(vector<int> &array){
        int n = array.size();
        //Size of largest increasing subsequence with ith index as last selected.
        vector<int> size(n, 1); 
        vector<int> hash(n, 0);

        int last = 0;
        for(int i=0; i<n; i++)  hash[i] = i;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(array[j]>array[i] && size[j]<(size[i]+1)){
                    size[j] = size[i]+1;
                    hash[j] = i;
                    last = j;
                }
            }
        }

        vector<int> seq;
        int i = last;

        while(hash[i]!=i){
            seq.push_back(array[i]);
            i = hash[i];
        }
        seq.push_back(array[i]);

        reverse(seq.begin(), seq.end());
        return seq;
    }
};

int main(){
    vector<int> cuts = {1,3,4,5,2};
    Solution newSol;
    vector<int> seq = newSol.largestIncreasingSubsequence(cuts);
    for(int i: seq) cout << i << " ";
    return 0;
}