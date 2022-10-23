// LeetCode - 56. Merge Interval.
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
// EXAMPLE:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]

#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int> &a, vector<int> &b){
    return (a[0]<b[0]);
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals){
        sort(intervals.begin(), intervals.end(), comparator);
        vector<vector<int>> range;
        
        int n = intervals.size();
        int i=0;
        while(i<(n-1)){
            // vector<int> &a = intervals[i], &b = intervals[i+1];
            // a[0] <= a <= a[1] & b[0] <= b <= b[1]

            if(intervals[i+1][0]<=intervals[i][1]){
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
                
                //Discard intervals[i] after merging:
                intervals[i][0] = -1; intervals[i][1] = -1;
            }
            else{
                range.push_back(intervals[i]);
            }
            
            i++;

        }
        range.push_back(intervals[i]);  //Push the last interval.

        return range;
    }
};

int main(){
    vector<vector<int>> intervals = {{2,6}, {1,3}, {8,10}, {15,18}};
    Solution find;
    find.merge(intervals);
    return 0;
}