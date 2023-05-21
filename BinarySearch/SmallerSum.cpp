// GFG: Smaller Sum.
// Description - You are given an array A of n integers. For each index i, you have to find the sum of all integers present in the array with a value less than A[i].

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Lower Bound
    int lbound(vector<int> &A, int value){
        int i=0, j=A.size()-1;
        int index = 0;
        while(i<=j){
            int midpoint = (i+j)/2;
            if(A[midpoint] >= value){ j = midpoint-1; index = midpoint; }
            else i = midpoint+1;
        }
        
        return index;
    }
    
    vector<long long> smallerSum(int n, vector<int> &given){
        vector<int> A = given;
        sort(A.begin(), A.end());
        
        vector<long long int> prefix(n+1, 0);
        for(int i=0; i<n; i++) prefix[i + 1] = prefix[i] + A[i];
        
        vector<long long int> solution(n, 0);
        for(int i=0; i<n; i++){
            int index = lbound(A, given[i]);
            solution[i] = prefix[index];
        }
        
        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}