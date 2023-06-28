// GFG/LeetCode - Task Scheduler 
// Description - https://practice.geeksforgeeks.org/problems/task-scheduler/1
// Given a character array tasks of size N, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
// CPU has a cooldown period for each task. CPU can repeat a task only after atleast K units of time has passed after it did same task last time. It can perform other tasks in that time, can stay idle to wait for repeating that task.
// Return the least number of units of times that the CPU will take to finish all the given tasks.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &A) {
        vector<int> F(26, 0);
        for(int i=0; i<N; i++) F[(A[i] - 'A')] += 1;
        priority_queue<int> maxheap;
        for(int &i: F) if(i > 0) maxheap.push(i);
        
        int counter = 0;    //Timer
        queue<pair<int, int>> q;    //Store the element till its cool down period. {element, time to add back to heap}
        while(!maxheap.empty() || !q.empty()){
            counter += 1;
            if(!q.empty() && q.front().second == counter){  //Check if the element in queue has completed cool down period.
                maxheap.push(q.front().first);  //Add the element back to heap.
                q.pop();
            }
            
            if(maxheap.empty() != true){
                int top = maxheap.top(); maxheap.pop();
                if(top > 1) q.push({top - 1, counter + K + 1});     //If the frequency > 0 add to the queue.
            }
            
        }
        
        return counter;
    }
};

int main(){
    Solution solve;
    
    return 0;
}