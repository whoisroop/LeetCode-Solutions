// LeetCode - 2439. Minimize Maximum of Array.
// Description - 
// You are given a 0-indexed array nums comprising of n non-negative integers.
// In one operation, you must:
// Choose an integer i such that 1 <= i < n and nums[i] > 0.
// Decrease nums[i] by 1.
// Increase nums[i - 1] by 1.
// Return the minimum possible value of the maximum integer of nums after performing any number of operations.

// Approach:
// Given two numbers, if we can increase one and decrease other: the point where they'll coincide is the average of the numbers.
// Similar is the case for more than two numbers given the average is an integer.
// In the problem, the value are flowing from right to left. Meaning the values of the left part can only increase & not decrease.
// Example: [3,7,1,6]
// The minimum max value in the array is 3, as it can not be decreased further. 
// However, (3, 7) can be reduced to its average: 5. Also 5 > 3, therefore 5 is the new minimum max value of the array.
// If the array was [7,3,...]: 
// The minimum max for (7) was 7.
// The minimum max for (7,3): Average = 5. But 5 < 7, the previous minimum max. The value remains unchanged of the minimum max.
// As the value flows to left, the average can only increase, hence no smaller minimum max can be found considering the right part of the array. Therefore can be avoided & the problem can be broken down.

// CEIL(x/n) = (x + (n-1))/n;

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& A) {
        int n = A.size();
        long long int sum = 0;
        int value = INT32_MIN;
        for(int i=0; i<n; i++){
            sum += A[i];
            int average = ((sum + (i + 1 - 1)) / (i + 1));  //To Calculate Ceil
            value = max(value, average);
        }

        return value;
    }
};

int main(){
    Solution solve;
    
    return 0;
}