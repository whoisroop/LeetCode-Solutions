//LeetCode 17. Letter Combinations of a Phone Number.
//NOT A DP PROBLEM: Multiply two subsets to create a subset.
//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

#include<iostream>  
#include<vector>
using namespace std;

class Solution{
public:
    vector<string> findCombinations(string &digits){
        if(digits==""){
            vector<string> empty;
            return empty;
        }
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> solution = {""};

        for(const char &digit: digits){
            vector<string> hold;
            for(const string &s: solution){
                for(const char &c: pad[(digit-'0')]){
                    hold.push_back((s+c));
                }
            }

            solution = hold;
        }

        return solution;
    }
};

int main(){
    string digits = "2";
    Solution find;
    find.findCombinations(digits);
    return 0;
}