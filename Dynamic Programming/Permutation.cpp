#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    void f(int index, vector<int> &array, vector<int> &ds, vector<vector<int>> &solution){
        if(ds.size() == array.size()){
            solution.push_back(ds);
            return;
        }

        for(int i=index; i>=0; i--){
            if(array[i]!=100){
                int value = array[i];
                array[i]=100;   //Mark Visited
                ds.push_back(value);
                f(index, array, ds, solution);
                ds.pop_back();
                array[i]=value; //Reset value & data structure that carries the sequence.
            }
        }

        return;
    }

    void permutationEfficient(int i, int li, vector<int> &array, vector<vector<int>> &solution){
        if(i==li){
            solution.push_back(array);
            return;
        }

        for(int j=i; j<=li; j++){
            //Try every element at index i & move ahead to i+1.
            swap(array[i], array[j]);
            permutationEfficient(i+1, li, array, solution);
            swap(array[i], array[j]);
        }

        return;
    }
    
public:
    vector<vector<int>> permutations(vector<int> &array){
        int n = array.size();
        vector<vector<int>> solution;
        // vector<int> ds;
        // f(n-1, array, ds, solution);

        permutationEfficient(0, (n-1), array, solution);

        for(int i=0; i<solution.size(); i++){
            for(int j=0; j<n; j++){
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }

        return solution;
    }

};

int main(){
    vector<int> array = {1,5,9};
    Solution newSol;
    newSol.permutations(array);

    return 0;
}