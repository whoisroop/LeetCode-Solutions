#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> fourSum(vector<int> &array, int target){
        //a+b+c+d = sum -> c+d = sum - (a+b)    Make a, b target & find d by two pointer
        sort(array.begin(), array.end());
        int li = array.size()-1;
        vector<vector<int>> sol;

        for(int i=0; i<=(li-3); i++){
            if(i==0 || array[i]!=array[i-1]){   //To eliminate identical quadruples.
                for(int j=i+1; j<=(li-2); j++){
                    if(j==(i+1) || array[j]!=array[j-1]){
                        long int findSum = target - ((1LL*array[i])+array[j]);  //Overflow Protection
                        int low = j+1; int high = li;
                        while(low<high){
                            long int sum = array[low]+array[high];
                            if(sum==findSum){
                                vector<int> temp;
                                temp.push_back(array[i]);
                                temp.push_back(array[j]);
                                temp.push_back(array[low]);
                                temp.push_back(array[high]);
                                sol.push_back(temp);

                                while(low<high && array[low]==array[low+1]) low++;
                                while(low<high && array[high]==array[high-1]) high--;
                                low++; high--;  //We stand on next distinct elements.
                            }

                            else if(sum<findSum)    low++;
                            else if(sum>findSum)    high--;
                        }
                    }
                }
            }
        }

        return sol;
    }

};

int main(){
    vector<int> array = {1,0,-1,0,-2,2};
    int target = 0;
    Solution newSol;
    vector<vector<int>> solution = newSol.fourSum(array, target);

    for(int i=0; i<solution.size(); i++){
        for(int j=0; j<solution[i].size(); j++){
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
