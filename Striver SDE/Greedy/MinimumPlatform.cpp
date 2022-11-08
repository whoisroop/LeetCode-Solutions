// GFG - Minimum Platform.
// Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
// Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.
// Example:
// Input: N = 6 
// arrival[] = {0900, 0940, 0950, 1100, 1500, 1800}
// departure[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3

#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
    return (a.second.second < b.second.second);
}

class Solution{
public:
    int findPlatform(int arrival[], int departure[], int n){
    	vector<pair<int, pair<int, int>>> train(n);    //<Index, <Arrival, Departure>>
        for(int i=0; i<n; i++){
            train[i] = {i, {arrival[i], departure[i]}};
        }

        sort(train.begin(), train.end(), comparator);

        int l = n; int platform = 0;
        while(l!=0){
            int pDepart = -1;
            for(int i=0; i<n; i++){
                int &arrive = train[i].second.first;
                int &depart = train[i].second.second;
                if(arrive == -1 || depart == -1) continue;  //Already Alloted Platform.

                if(arrive > pDepart){
                    cout << arrive << " - " << depart << endl;
                    l--; pDepart = depart;
                    arrive = -1; depart = -1;   //Mark as alloted.
                }
            }

            platform++;
            cout << "* * * * *" << endl;
        }

        return platform;
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