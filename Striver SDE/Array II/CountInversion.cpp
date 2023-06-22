// GFG: Count Inversions. 
// Description: Wwo elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j. 
// Approach: 
// To find the pair such that element on left is greater then element on right, normally takes O(N^2).
// To find the pair:
// [3 4 6 7 9] [1 2 2 5 8]
// To find the pairs from two sorted vector: L & R
// Element Of Left < Element Of Right: USE TWO POINTER APPROACH
// While(R[j] < L[i]) j += 1;
// [(3) 4 6 7 9] [(1 2 2) 5 8]
//   i                    j
// The elements 0 1 ... j-1 of R < L[i]
// Pair += j

// Now i += 1 the value of L[i+1] >= L[i] the arrays are sorted.
// The elements 0 1 ... j-1 < L[i], Therefore also < L[i+1] from the current position increment the value j from the current position, applying the same condition.
// O(N)

// To divide an array into sorted left & right components: MERGE SORT.
// Every possible combination of L & R are included.
 
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<long long int> mergesort(int i, int j, vector<long long int> &A, long long int &counter){
        if(i == j) return {A[i]};
        
        int midpoint = (i + j)/2;
        vector<long long int> L = mergesort(i, midpoint, A, counter);
        vector<long long int> R = mergesort(midpoint + 1, j, A, counter);
        
        // COUNTING:
        int pL = 0, pR = 0;
        while(pL < L.size()){
            while(pR < R.size() && R[pR] < L[pL]) pR += 1;
            
            counter += (pR);
            pL += 1;
        }
        
        vector<long long int> X((j-i + 1), 0);
        int m = 0, n = 0;
        
        int index = 0;
        while(m < L.size() && n < R.size()){
            if(L[m] <= R[n]) X[index++] = L[m++];
            else X[index++] = R[n++];
        }
        
        while(m < L.size()) X[index++] = L[m++];
        while(n < R.size()) X[index++] = R[n++];
        
        for(int x=i; x<=j; x++) A[x] = X[x-i];
        return X;
    }
    
    long long int inversionCount(long long given[], long long N){
        vector<long long int> A(given, given+N);
        
        long long int counter = 0;
        vector<long long int> sorted = mergesort(0, N-1, A, counter);
        
        return counter;
    }

};

int main(){
    Solution solve;
    
    return 0;
}