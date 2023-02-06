// LeetCode - 60. Permutation Sequence. Find Kth Sequence.
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void permute(string &current, int k, vector<int> &A, vector<int> &F){
        int n = A.size();
        if(k == 0){ for(int i: A) current += (i + '0'); return; }

        int index = (k/F[n - 1]);

        current += (A[index] + '0');
        A.erase(A.begin() + index);
        
        k -= (index)*(F[n - 1]);

        permute(current, k, A, F);

        return;
    }

    string getPermutation(int n, int k) {
        vector<int> A(n, 0);
        for(int i=1; i<=n; i++) A[i - 1] = i;

        vector<int> F(n, 1);    //Factorial
        for(int i=1; i<n; i++) F[i] = i * F[i - 1];

        string solution = "";
        permute(solution, k - 1, A, F);

        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}