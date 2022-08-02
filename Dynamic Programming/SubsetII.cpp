#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void f(int i, int li, vector<int> &array, vector<int> sequence, vector<vector<int>> &subsets){
        if(i>li){
            subsets.push_back(sequence);
            return;
        }

        int taken=(-999);
        for(int j=i; j<=(li+1); j++){
            if(j==li+1) f(j, li, array, sequence, subsets); //Case to cover not take anything.

            else if(array[j]!=taken){
                taken = array[j];
                sequence.push_back(array[j]);
                f(j+1, li, array, sequence, subsets);
                sequence.pop_back();
            }
        }

        return;
    }

public:
    vector<vector<int>> uniqueSubsets(vector<int> array){
        sort(array.begin(), array.end());
        int li = array.size()-1;
        vector<int> sequence;
        vector<vector<int>> subsets;
        f(0, li, array, sequence, subsets);

        for(int i=0; i<subsets.size(); i++){
            for(int j=0; j<subsets[i].size(); j++){
                cout << subsets[i][j] << " ";
            }
            cout << endl;
        }

        return subsets;
    }

};

int main(){
    vector<int> array = {0};
    Solution newSol;
    newSol.uniqueSubsets(array);
    return 0;
}