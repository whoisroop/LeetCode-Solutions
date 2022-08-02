#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    void recursion(vector<int> input, vector<vector<int>> &solution, vector<int> &subseq, int index = 0){
        int n = input.size();
        if(index >= n){
            solution.push_back(subseq);
            return;
        }

        //Didn't take the element
        recursion(input, solution, subseq, index+1);

        //Take the element
        subseq.push_back(input[index]); 
        recursion(input, solution, subseq, index+1);
        subseq.pop_back();
    }

    vector<vector<int>> subsets(vector<int> &input){
        vector<vector<int>> ans;
        vector<int> subseq;
        recursion(input, ans, subseq, 0);

        return ans;
    }
};