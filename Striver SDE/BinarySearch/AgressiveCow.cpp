// GFG : Aggresive Cow.
// You are given an array consisting of N integers which denote the position of a stall. You are also given an integer K which denotes the number of aggressive cows. 
// You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// Approach:
// Here, we apply the binary search on answer & check for the given predicted value i.e. predict the gap between stalls and for that count the number to cows that can be accomodated.
// If the number of cows accomodated are lesser than the given cows, decrease the gap and vice versa.
// Find the maximum value that satisfies the condition.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cowsWithGap(vector<int> &stalls, int gap){
        int n = stalls.size();
        int counter=0;
        int previous=0;
        for(int i=0; i<n; i++){
            if(i==0 || stalls[i] >= (previous + gap)){
                previous = stalls[i];
                counter++;
            }
        }
        
        return counter;
    }
    
    int solve(int n, int cows, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int i=0, j=0;
        for(int &p: stalls) j=max(j, p);
        int midpoint;
        
        while(i<=j){
            midpoint = (i+(j-i)/2);
            
            int accomodated = cowsWithGap(stalls, midpoint);
            
            // cout << i << " , " << j << " = " << midpoint << " | " << accomodated << endl;
            if(accomodated < cows) j=midpoint-1;
            else i=midpoint+1;
        }
        
        return j;
    }
};