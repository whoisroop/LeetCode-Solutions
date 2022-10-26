// LeetCode -  169. Majority Element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Moore's Voting Algorithm:
// If the occurence of an element is greater than half of all the elements or votes for a candidate is greater than half the total votes:
// If for every vote of the Majority Element (ME), if we eliminate its vote with that of every other candidate, in the end we remain with ME votes.

// 7 7 5 7 5 1 | 5 7 | 5 5 7 7 | 5 5 5 5
//    ME: 7     ME: 5    ME:5     ME:5

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &A) {
        int n = A.size();
        
        //Moore's Voting
        int vote=0; int candidate;
        
        for(int i=0; i<n; i++){
            if(vote==0) candidate = A[i];
            
            if(candidate == A[i]) vote++;
            else vote--;
        }
        
        return candidate;
    }
};