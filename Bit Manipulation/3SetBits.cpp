// Problem - Akku & Binary Numbers. 
// Link - https://practice.geeksforgeeks.org/problems/akku-and-binary-numbers0902/1?page=1&status[]=attempted&sortBy=submissions
// Description - Akku likes binary numbers and she likes playing with these numbers. Her teacher once gave her a question.For given value of  L and R, Akku have to find the count of number X, which have only three-set bits in it's binary representation such that "L ≤ X ≤ R".

// Approach:
// Generate the search space, generate all the elements with 3 set bits & use binary search to yeild answer.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
vector<long long int> A;

    void precompute(){
        for(int i=0; i<63; i++){
            for(int j=i+1; j<63; j++){
                for(int k=j+1; k<63; k++){
                    long long int value = 0;
                    value |= ((1LL << i) | (1LL << j) | (1LL << k));
                    A.push_back(value);
                }
            }
        }
        
        sort(A.begin(), A.end());
        return;
    }
    
    long long solve(long long minV, long long maxV){
        int R = (upper_bound(A.begin(), A.end(), maxV) - A.begin());
        int L = (lower_bound(A.begin(), A.end(), minV) - A.begin());
        
        return (R - L);
    }
    
};

int main(){
    Solution solve;
    
    return 0;
}