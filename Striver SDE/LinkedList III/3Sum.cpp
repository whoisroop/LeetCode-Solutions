// LeetCode - 15. Three Sum.
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
// and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &A) {
        int n = A.size();
        // A + B + C = T
        // B + C = (T - A)
        
        vector<vector<int>> solution;
        if(n<3) return solution;
        
        sort(A.begin(), A.end());
        
        int sum = 0;    //Sum = Target
        for(int ia=0; ia<(n-2); ia++){
            if(ia!=0 && A[ia] == A[ia-1]) continue;
            
            sum -= A[ia];
            
            int ib = (ia+1), ic = (n-1);
            while(ib<ic){
                if(ib!=(ia+1) && A[ib] == A[ib-1]){ ib++; continue; }   //To eliminate duplicate cases.
                if(ic!=(n-1) && A[ic] == A[ic+1]){ ic--; continue; }
                
                int total = A[ib] + A[ic];
                
                if(total == sum){
                    vector<int> triples(3, 0);
                    triples[0] = A[ia]; 
                    triples[1] = A[ib]; 
                    triples[2] = A[ic];
                    solution.push_back(triples);
                    ib++; ic--;
                }
                
                else if(total > sum) ic--;
                else if(total < sum) ib++;
            }
            
             sum += A[ia];
        }
        
        return solution;
    }
    
};

// FASTER SOLUTION:

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int> &A) {
//         int n = A.size();
//         // A + B + C = T
//         // B + C = (T - A)
        
//         vector<vector<int>> solution;
//         if(n<3) return solution;
        
//         sort(A.begin(), A.end());
        
//         int sum = 0;    //Sum = Target
//         for(int ia=0; ia<(n-2); ia++){
//             if(ia!=0 && A[ia] == A[ia-1]) continue;
            
//             sum -= A[ia];
            
//             int ib = (ia+1), ic = (n-1);
//             while(ib<ic){
//                 int total = A[ib] + A[ic];
                
//                 if(total == sum){
//                     vector<int> triples(3, 0);
//                     triples[0] = A[ia]; triples[1] = A[ib]; triples[2] = A[ic];
//                     solution.push_back(triples);
                    
//                     while(ib<ic && A[ib] == A[ib+1]) ib++;
//                     while(ib<ic && A[ic] == A[ic-1]) ic--;
//                     ib++; ic--;
//                 }
                
//                 else if(total > sum) ic--;
//                 else if(total < sum) ib++;
//             }
            
//              sum += A[ia];
//         }
        
//         return solution;
//     }
    
// };