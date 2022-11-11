// GFG - Minimum Platform.
// Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
// Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.
// Example:
// Input: N = 6 
// arrival[] = {0900, 0940, 0950, 1100, 1500, 1800}
// departure[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3

// Refer Book - Guide To Cp.

// We need to find the maximum number of overlapping i.e. the max needed platforms = max number of train encountered at a moment.
// Sweep Line Algorithm: Sort the incoming time & out going time - Add one for every incoming & Subtract one for every out going while traversing through time.

#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
    return (a.second.second < b.second.second);
}

class Solution{
public:
    int findPlatform(int arrival[], int departure[], int n){
    	sort(arrival, arrival + n);
    	sort(departure, departure + n);
    	int overlap = 0;	//+1 For Each Entry & -1 Fir Each Exit
    	int maxtrain = 0;
    	
    	int i=0, j=0;
    	while(i<n){
    	    while(departure[j] < arrival[i]){
    	        overlap--; j++;
    	    }
    	    overlap++; i++;
    	    maxtrain = max(maxtrain, overlap);
    	}
    	
    	return maxtrain;
    }
};

int main(){
    int arrival[] = {900, 940, 950, 1100, 1500, 1800};
    int departure[] = {910, 1200, 1120, 1130, 1900, 2000};
    int N = 6;
    Solution find;
    cout << find.findPlatform(arrival, departure, N);

    return 0;
}