//LeetCode - 216. Combination Sum III
//Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    void find(int index, int target, int size, vector<int> &array, vector<int> &subset, vector<vector<int>> &solution){
        if(size==0){
            if(target==0){
                solution.push_back(subset);
                return;
            }
            else return;
        }
        
        if(index<0) return;

        //Take Case:
        if(target>=array[index]){
            subset.push_back(array[index]);
            find(index-1, target-array[index], size-1, array, subset, solution);
            subset.pop_back();
        }

        //NotTake Case:
        find(index-1, target, size, array, subset, solution);

        return;
    }

    vector<vector<int>> findCombinations(int target, int k){
        vector<int> array(9, 0);
        for(int i=0; i<9; i++) array[i]=i+1;
        int li = 8;

        vector<int> subset;
        vector<vector<int>> solution;
        
        find(li, target, k, array, subset, solution);

        for(int i=0; i<solution.size(); i++){
            for(int j=0; j<k; j++) cout << solution[i][j] << " ";
            cout << endl;
        }
        return solution;
    }
};

int main(){
    Solution find;
    find.findCombinations(7,3);
    return 0;
}