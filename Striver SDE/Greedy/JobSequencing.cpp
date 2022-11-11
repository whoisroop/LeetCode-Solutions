// GFG - Job Sequencing Problem.
// Given a set of N jobs where each jobi has a deadline and profit associated with it.
// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.
// Find the number of jobs done and the maximum profit.
// Note: Jobs will be given in the form (Job id, Deadline, Profit) associated with that Job.

// Sequencing : Arrange the jobs in order such that max profit is obtained. REWARD & DEADLINE BASED.

#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int deadline; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool comparator(Job &A, Job &B){
    return (A.profit > B.profit);
}

class Solution {
public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job A[], int n) { 
        sort(A, A + n, comparator);
        vector<int> time(101, -1);  //Time slot. Time[t] = The ID of job performed at the moment (t-1) to t.
        int jobs = 0; int profit = 0;
        
        for(int i=0; i<n; i++){
            int j = A[i].deadline;
            while(j>0 && time[j] != -1) j--;
            
            if(j>0){
                time[j] = A[i].id;
                profit += A[i].profit;
                jobs++;
            }
        }
        
        vector<int> result(2, 0);
        result[0] = jobs; result[1] = profit;
        return result;
    } 
};