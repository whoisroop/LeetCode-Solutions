// LeetCode - 53. Maximum Subarray.
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// Kandane's Algorithm:
// For the given question, while traversing the array, at an index i, you have two options: 
// OPTIONS: 1) Append the element to the existing subarray. OR 2) Start a new subarray.

// How to decide:
// If the previous subarray contributes a negative sum, the overall sum decreases, hence start a new subarray.
// If the previous subarray contributes a positive sum, the overall sum increases, hence continue the previous, append to subarray.

// Here the implementation of KANDANE ALGORITHM is through sliding window: More Intuitive.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int findMaxSum(vector<int> &array){
        int n = array.size();

        int i=0, j=0;
        int sumW = 0;    //WindowSum
        int maxi = -1e9;   int sizeW;

        while(j<n){
            sumW += array[j];
            
            if(array[j] > sumW){
                sumW = array[j];
                i = j;
            }

            maxi = max(maxi, sumW);
            if(maxi == sumW) sizeW = (j-i+1);
            j++;
        }

        cout << "MAXIMUM SUBARRAY: " << endl;
        cout << "SIZE: " << sizeW << " & SUM: " << maxi << endl;

        return maxi;
    }
};

int main(){
    Solution find;
    vector<int> array = {-2,1,-3,4,-1,2,1,-5,4};

    find.findMaxSum(array);
    return 0;
}