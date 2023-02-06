#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        int n = tasks.size();
        int rounds = 0;

        int p = 0;  //Previous Pointer
        for(int i=0; i<n; i++){
            if(i == 0) continue;

            if(tasks[i] != tasks[i-1]){
                int total = (i - p);
                if(total == 1) return -1;
                rounds += ceil(total/3.0); 
                p = i;
            }

        } 

        if((n-p) == 1) return -1;
        else rounds += ceil((n-p)/3.0);

        return rounds;
    }
};