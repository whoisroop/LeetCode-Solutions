// GFG : Schedule - N Meetings In A Room.
// There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
    return (a.second.second < b.second.second);
}

class Solution{
public:
    int maxMeetings(int start[], int end[], int n){
        vector<pair<int, pair<int, int>>> meeting(n);   // <Index, <Start, End>>
        for(int i=0; i<n; i++){
            meeting[i] = {i, {start[i], end[i]}};
        }

        sort(meeting.begin(), meeting.end(), comparator);
        int counter = 0; int endTime = -1;
        for(int i=0; i<n; i++){
            int start = meeting[i].second.first; int end = meeting[i].second.second;
            if(start > endTime){
                counter++;
                endTime = end;
            }
        }

        return counter;
    }
};