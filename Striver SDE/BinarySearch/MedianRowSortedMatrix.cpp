// GFG - Median Of Row Sorted Matrix.
// Binary Search On Answer.
// Predict a value and check the elements lesser than the predicted value in the array using upper bound concept.
// Make sure the predicted value is the smallest one that satisfies the condition, makes sure that the element is actually present in the arrays.
// For Example: {1, 3, 5, 7, 9}
// The value 5 & 6 satisfies the elements lesser that the predicted value = N/2. However, 6 cannot be a candidate because it is not present in array.
// The smallest value that satisfies the condition that elements lesser than predicted value is N/2, is 5. 
// Because the flow will break at the element that is present in the array.

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int eLeft = (R*C)/2;
        int i=0, j=2000;
        int midpoint;
        
        while(i<=j){
            midpoint = (i + (j-i)/2);
            int elements = 0;
            for(int i=0; i<R; i++) elements += (upper_bound(matrix[i].begin(), matrix[i].end(), midpoint) - matrix[i].begin());
            elements -= 1; //The midpoint or predicted value is included.
            
            if(elements >= eLeft) j = midpoint-1;
            else i = midpoint+1;
        }
        
        int median = i;
        return median;
    }
};