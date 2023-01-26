// LeetCode : 435. Non-overlapping Intervals.
// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Thought Process: [pA, pB] & [qA, qB]
// First find the max of (pA, qA) & min of (pB, qB):
// If (qA, qB) is an overlapping interval with (pA, pB) then to test: qB >= min(pA, qA) && qA <= max(pB, qB) with overlap max(pA, qA) to min(pB, qB).

#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int> &a, vector<int> &b){
    return (a[1] < b[1]);   //Adding <= results in an error! - runtime error: applying non-zero offset 4 to null pointer(stl_vector.h)
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();

        //Overlapping xmin & xmax:
        int xmin = points[0][0];
        int xmax = points[0][1];
        int overlap = 0;
        for(int i = 1; i<n; i++){
            xmin = max(xmin, points[i][0]);
            xmax = min(xmax, points[i][1]);

            if(points[i][0] < xmax && points[i][1] > xmin) overlap += 1;    //TO IDENTIFY OVERLAP
            else{
                xmin = points[i][0];
                xmax = points[i][1];
            }
        }

        return overlap;
    }

    int optimalEvents(vector<vector<int>> &time){
        int n = time.size();
        sort(time.begin(), time.end(), comparator);

        int END = INT32_MIN;
        int events = 0;
        for(int i=0; i<n; i++) if(time[i][0] > END){ END = time[i][1]; events += 1; }

        return (n - events);
    }
};