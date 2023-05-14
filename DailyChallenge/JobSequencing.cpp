// LeetCode - Job Sequencing Problem.
// Description - Given a set of N jobs where each job i has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.

// Approach:
// Sort the job on the basis of maximum reward, check if a slot is available for the given deadline.
// Book the last most time slot for the job. So other jobs with early deadlines can also be accomplished.

#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution {
public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job A[], int n) 
    { 
        priority_queue<pair<int, int>> pq; //<Reward, Deadline>
        bitset<101> schedule;
        
        for(int i=0; i<n; i++) pq.push({A[i].profit, A[i].dead});
        
        int counter = 0;
        int total = 0;
        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            int profit = top.first;
            int deadline = top.second;
            
            bool slot = false;
            for(int i=deadline; i>0; i--){
                if(schedule[i] == 0){ 
                    schedule[i] = 1; slot = true; 
                    counter += 1; total += profit;
                    break; 
                }
            }
        }
        
        return {counter, total};
    } 
};

int main(){
    Solution solve;
    
    return 0;
}