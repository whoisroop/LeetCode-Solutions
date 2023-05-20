// GFG - Find K-th Smallest Element In Given N Ranges.
// Description - Given n ranges of the form [p, q] which denotes all the numbers in the range [p, p + 1, p + 2,...q].  Given another integer q denoting the number of queries. The task is to return the kth smallest element for each query (assume k>1) after combining all the ranges.
// In case the kth smallest element doesn't exist return -1. 

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(), range.end());
        vector<int> solution(q, -1);
        
        for(int i=0; i<q; i++){
            int K = queries[i];
            for(int j=0; j<n; j++){
                if(j != 0 && range[j-1][1] >= range[j][0]) range[j][0] = range[j-1][1] + 1;
                
                if((range[j][1] - range[j][0] + 1) >= K){
                    solution[i] = range[j][0] + K - 1;
                    break;
                }
                else K -= (range[j][1] - range[j][0] + 1);
            }
        }
        
        return solution;
    } 
};
int main(){
    Solution solve;
    
    return 0;
}