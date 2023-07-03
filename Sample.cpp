// LeetCode - 
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void make(int index, string current, string &A, unordered_map<string, int> &F){
        int n = A.size();
        if(index == n){ F[current] += 1; return; }

        // Take:
        make(index+1, current + A[index], A, F);
        // Not Take:
        make(index+1, current, A, F);

        return;
    }

public:
    int LongestRepeatingSubsequence(string A){
        A = "axxzxy";
        unordered_map<string, int> F;
        make(0, "", A, F);

        string result = ""; int maxF = 0;
        for(auto &i: F) cout << i.first << " - " << i.second << endl;

        int sum = 0;
        for(auto &i: F) sum += i.second;
        cout << "\n\n SUM: " << sum << endl;
        cout << "R: " << result << " " << maxF << endl;
        return maxF;
    }
};

int main(){
    Solution solve;
    solve.LongestRepeatingSubsequence("");
    return 0;
}