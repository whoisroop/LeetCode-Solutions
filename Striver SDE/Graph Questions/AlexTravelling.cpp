// GFG: Alex Travelling 
// Description: Alex is very fond of traveling. There are n cities, labeled from 1 to n.  You are also given flights, a list of travel flights as directed weighted edges flights[i] = (ui,vi,wi) where ui is the source node, vi is the target node, and wi is the price it takes for a person to travel from source to target.
// Currently, Alex is in k'th city and wants to visit one city of his choice. Return the minimum money Alex should have so that he can visit any city of his choice from k'th city. If there is a city that has no path from k'th city, which means Alex can't visit that city, return -1. 
// Alex always takes the optimal path. He can any city via another city by taking multiple flights.

// Approach: Single Source Shortest Path.

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
public:
    int maxmax = 1e8;
    int mincost(vector<vector<int>> &flights, int N, int source){
        // Bellman Ford's:
        vector<int> distance(N+1, maxmax);
        distance[source] = 0;

        for(int i=0; i<N-1; i++){
            for(auto &edge: flights){
                int A = edge[0], B = edge[1], W = edge[2];

                if(distance[A] + W < distance[B]) distance[B] = distance[A] + W;
            }
        }

        int maxV = 0;
        for(int i=1; i<=N; i++) maxV = max(maxV, distance[i]); 

        return maxV;
    }
  
};

int main(){
    Solution solve;
    vector<vector<int>> flights(3);
    flights[0].push_back(2);
    flights[0].push_back(1);
    flights[0].push_back(1);
    flights[1].push_back(2);
    flights[1].push_back(3);
    flights[1].push_back(1);
    flights[2].push_back(3);
    flights[2].push_back(4);
    flights[2].push_back(1);

    cout << solve.mincost(flights, 4, 2);
    return 0;
}