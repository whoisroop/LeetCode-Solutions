//Divide the given array into two partitions such that their absolute difference is min.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    //Tabulation
    int minSubsetDiff(vector<int> array){
        int n = array.size() - 1;
        int totalSum = 0;
        for(int x:array)    totalSum+=x;    //Total sum of elements in array.
        int target = totalSum;

        vector<int> prev(1e5, 0);  //For Index i-1
        vector<int> curr(1e5, 0);  //For Index i

        prev[array[0]] = 1;    //For Base Case Index 0
        prev[0] = curr[0] = 1;  //For all n.

        for(int i=1; i<=n; i++){
            for(int t=1; t<=target; t++){
                bool take = false, notTake = false;
                if(t>=array[i]) take = prev[t-array[i]];
                notTake = prev[t];

                curr[t] = (take||notTake);
            }

            prev = curr;
        }
        
        int mini = 1e9;
        
        for(int t=0; t<=target/2; t++){
            if(prev[t]==1){
                int difference = ((totalSum - t) - (t));    //(S2 - S1)
                // cout << t << " - " << difference << endl;
                mini = min(mini, difference);
            } 
        }

        return mini;
    }

};

int main(){
    vector<int> array = {3,2,7};
    Solution newSol;
    cout << "MIN DIFFERENCE: " << newSol.minSubsetDiff(array);
}