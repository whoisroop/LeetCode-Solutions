//LeetCode - 77. Combinations.
//Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public: 
    void find(int index, int k, vector<int> &array, vector<int> &subset, vector<vector<int>> &solution){
        if(k==0){
            solution.push_back(subset);
            return;
        }
        if(index<0) return;

        //Take:
        subset.push_back(array[index]);
        find(index-1, k-1, array, subset, solution);
        subset.pop_back();

        //NotTake:
        find(index-1, k, array, subset, solution);

        return;
    }

    vector<vector<int>> combinations(int n, int k){
        vector<int> array(n, 0);
        for(int i=0; i<n; i++) array[i] = i+1;

        vector<int> subset;
        vector<vector<int>> solution;
        find(n-1, k, array, subset, solution);

        for(int i=0; i<solution.size(); i++){
            for(int j=0; j<k; j++) cout << solution[i][j] << " ";
            cout << endl;
        }

        return solution;
    }
};

int main(){
    Solution find;
    find.combinations(4,2);
    return 0;
}