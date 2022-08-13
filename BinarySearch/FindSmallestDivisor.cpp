// LeetCode - 1283
// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold. Each result of the division is rounded to the nearest integer greater than or equal to that element.

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    bool sum(vector<int> &array, int divisor, int threshold){
        int n=array.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum += ceil((array[i]*1.0)/divisor);
        }
        
        return (sum<=threshold);
    }
    
    int smallestDivisor(vector<int>& array, int threshold) {
        int i=1; int j=0;
        for(const int &x: array)    j=max(j, x);
        int midpoint;
        
        while(i<=j){
            midpoint = i + (j-i)/2;
            
            //If sum is lesser then decrease the divisor.
            if(sum(array, midpoint, threshold)) j=midpoint-1;   
            else i=midpoint+1;
        }
        
        return i;
    }
};