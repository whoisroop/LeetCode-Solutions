// LeetCode - 229. Majority Element II.
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// #include<iostream>
// #include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &A) {
        int n = A.size();
        
        //Moore's Voting
        //There can be max of two candidates with vote > (N/3)
        //Hence, repeat the moore's voting algorithm this time taking two candidates

        int a = INT32_MAX, b = INT32_MAX;   //Candidate A & B
        int va = 0, vb = 0; //Votes For A & B

        for(int i=0; i<n; i++){
            if(a == A[i]) va++;
            else if(b == A[i]) vb++;
            else if(va == 0) {a = A[i]; va = 1;}
            else if(vb == 0) {b = A[i]; vb = 1;}
            else{   //Any Element Other Than The Two Candidates:
                va--; vb--;
            }
        }
        
        vector<int> solution;
        
        int ca = 0, cb = 0;
        // Count Occurence Of Majority Candidates:
        for(int &i: A){
            if(i == a) ca++;
            if(i == b) cb++;
        }
        
        if(ca > (n/3)) solution.push_back(a);
        if(cb > (n/3)) solution.push_back(b);
        
        return solution;
    }

    // Using Two Pointer:
    vector<int> majorityTP(vector<int> &A){
        int n = A.size();
        sort(A.begin(), A.end());

        vector<int> solution;

        int i=0, j=0;
        while(j<n){
            if(j==(n-1) || A[j]!=A[j+1]){
                if((j-i+1) > (n/3)) solution.push_back(A[j]);
                i = j+1;
            }

            j++;
        }

        return solution;
    }
};

int main(){
    vector<int> A = {2,2};
    Solution find;

    vector<int> x = find.majorityTP(A);
    for(int i: x) cout << i << " ";

    return 0;
}