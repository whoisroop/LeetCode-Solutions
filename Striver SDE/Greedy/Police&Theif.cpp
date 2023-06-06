// GFG - Police and Thieves.
// Description - Given an array of size n such that each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police. 
// Keep in mind the following conditions :

// Each policeman can catch only one thief.
// A policeman cannot catch a thief who is more than K units away from him.

// Approach:
// Catch the leftmost uncaught theif.
// CASE: T P T T T P P ; K = 2
// If T (P) T [T] T P P : P catches the theif at the max distance within range, consider the fact that the theives on the left side are getting out of scope and will not be caught in future as the police will be at a greater distance.
// Optimal: The 1st police catches 1st theif & the 2nd & 3rd catches 3rd & 4th theif.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int catchThieves(char A[], int n, int k){
        int counter = 0;
        for(int i=0; i<n; i++){
            if(A[i] == 'T' || A[i] == '.') continue;
            
            int p = max(0, i-k);
            int q = min(n-1, i+k);
            while(p <= q){
                if(A[p] == 'T'){
                    counter += 1; A[p] = '.';
                    break;
                }
                
                p += 1;
            }
        }
        
        return counter;
    }
};

int main(){
    Solution solve;
    
    return 0;
}