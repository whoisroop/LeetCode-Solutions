#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void f(int i, int target, vector<int> &array, vector<int> sequence, vector<vector<int>> &answer){
        if(target==0){
            answer.push_back(sequence);
        }
        
        if(i<0) return;
        
        //Restricting conditions on take. We do not have traditional take & notTake case.
        //If the value is already taken once do not choose or take again.
        //Hence, we're dictating on how to take.
        int taken = -1;
        for(int x=i; x>=0; x--){
            if(array[x]<=target && taken!=array[x]){
                taken = array[x];
                sequence.push_back(array[x]);
                f(x-1, target-array[x], array, sequence, answer);
                sequence.pop_back();
            }    
        }
        
        return;
    }

public:
    
    vector<vector<int>> combinationSumII(vector<int>& candidates, int target) {
        vector<vector<int>> answers;
        vector<int> sequence;
        sort(candidates.begin(), candidates.end(), greater<int>());
        f(candidates.size()-1, target, candidates, sequence, answers);
        
        for(int i=0; i<answers.size(); i++){
            for(int j=0; j<answers[i].size(); j++){
                cout << answers[i][j] << " ";
            }
            cout << endl;
        }
        
        return answers;
    }
};

int main(){
    vector<int> array = {10,1,2,7,6,1,5};
    int target = 8;
    Solution newSol;

    newSol.combinationSumII(array, target);

    return 0;
}