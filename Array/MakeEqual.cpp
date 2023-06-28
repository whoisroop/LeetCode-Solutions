// GFG - Swapping pairs make sum equal.
// Description - Given two arrays of integers A[] and B[] of size N and M, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

// APPROACH:
// Two pointers but in a different way:
// Let the sum of vector A > sum of vector B.
// We need to swap a greater element of A with a smaller element of B to curb the difference in sum.
// SUM A - SUM B = D
// Find a pair: SUMA - A[i] + B[j] = SUMB - B[j] + A[i]
// SUMA - D = SUMB + D
// SUMA - SUMB = 2xD
// D = (SUMA - SUMB)/2
// Find the values of A[i] B[j] such that, A[i] - B[j] or D = (SUMA - SUMB)/2
// Start the pointers i & j from the 0th index of sorted arrays.
// A[i] - B[j] : To increase the difference - Increase A[i] or i += 1;
// To decrease the difference - Increase B[j] or j += 1;

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int findSwapValues(int A[], int n, int B[], int m){
        int asum = accumulate(A, A+n, 0);
        int bsum = accumulate(B, B+m, 0);
        
        vector<int> X, Y;
        if(asum > bsum){ X = vector<int>(A, A+n); Y = vector<int>(B, B+m); }
        else { X = vector<int>(B, B+m); Y = vector<int>(A, A+n); }
        
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        
        int sumX = 0; for(int &i: X) sumX += i;
        int sumY = 0; for(int &i: Y) sumY += i;
        
        if((sumX-sumY) % 2 != 0) return -1;
        int target = (sumX - sumY)/2;
        
        int i = 0, j = 0;
        while(i < X.size() && j < Y.size()){
            int D = X[i] - Y[j];
            if(D == target) return 1;   //SUMX - D = SUMY + D : SUMX - SUMY = 2xD : D = (SUMX - SUMY) / 2
            
            if(D < target) i += 1;
            else j += 1;
        }
        
        return -1;
	}

};

int main(){
    Solution solve;
    
    return 0;
}