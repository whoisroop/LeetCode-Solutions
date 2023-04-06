// LeetCode - 881. Boats to Save People.
// Description - You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
// Return the minimum number of boats to carry every given person.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int counter = 0;
        int i=0, j=people.size()-1;
        while(i<=j){
            int sum = people[j]; j-=1;
            if(i<=j && sum + people[i] <= limit){
                sum += people[i]; i+=1;
            }

            counter += 1;
        }

        return counter;
    }
};

int main(){
    Solution solve;
    
    return 0;
}