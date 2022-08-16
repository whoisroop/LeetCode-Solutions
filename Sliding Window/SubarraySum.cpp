// Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int findSize(vector<int> &array, int target){
        int i=0; int j=0;

        int sum=0;
        int mini = INT32_MAX;
        int n = array.size();
        while(j<n){
            cout << i << " | " << j << " - " << mini << endl;
            if(i>j){ sum -= array[i]; i=j+1; j=j+1; }

            sum += array[j];

            if(sum==target){ 
                cout << "TARGET" << endl;
                mini = min(mini, (j-i+1));

                sum -= array[i];
                i++; j++;
            }
            else if(sum<target){
                j++;
            }
            else{   //sum>target
                sum -= array[i];
                i++;
            }
        }

        return mini;
    }
};

int main(){
    vector<int> array = {2,3,1,2,4,3};
    Solution find;
    cout << find.findSize(array, 7);
    return 0;
}