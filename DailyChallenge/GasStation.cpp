// LeetCode - 134. Gas Station
// Description - 
// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:

public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int total_fuel = 0, total_cost = 0;
        int start = 0;
        int fuel = 0;

        for(int i=0; i<n; i++){
            total_fuel += gas[i];
            total_cost += cost[i];
            
            fuel += gas[i];
            fuel -= cost[i]; //To travel from ith to (i+1)th station.

            // If you can't reach the next station after fueling up at the current:
            if(fuel < 0){
                // Reset the starting station & fuel:
                start = (i + 1);
                fuel = 0;
            }
        }

        // If total reward is greater than the total cost, there will exist a solution.
        if(total_fuel >= total_cost) return start;
        else return -1; 
    }
};

int main(){
    Solution solve;
    
    return 0;
}