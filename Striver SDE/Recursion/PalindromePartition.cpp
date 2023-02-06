// LeetCode - 131. Palindrome Partitioning
// Description - 
// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_palindrome(string &s){
        if(s == "") return false;

        int i = 0; int j = s.size() - 1;
        while(i <= j){
            if(s[i] != s[j]) return false;
            i += 1; j -=1;
        }
        return true;
    }

    void partition(int index, string current, string &given, vector<string> &subset, vector<vector<string>> &solution){
        int n = given.size();
        if(index == n){ if(current == "") solution.push_back(subset); return; }
        
        current += given[index];
        // Partition:
        if(is_palindrome(current)){
            subset.push_back(current);
            partition(index + 1, "", given, subset, solution);
            subset.pop_back();
        }

        // No Partition:
        partition(index + 1, current, given, subset, solution);

        return;
    }

    vector<vector<string>> palindrome_partition(string given) {
        int n = given.size();
        vector<string> subset;
        vector<vector<string>> solution;
        partition(0, "", given, subset, solution);

        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}