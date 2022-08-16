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
        bool changeJ = true;
        while(j<n){
            if(i>j){ j=i; continue; }
            
            if(changeJ) sum += array[j];

            if(sum>=target){
                mini = min(mini, (j-i+1));
                cout << "HIT: " << i << " " << j << " | SUM: " << sum << " - " << j-i+1 << endl;
                //As the sum is greater remove the first element of window.
                sum = sum - array[i];
                cout << "SUM: " << sum << endl;
                i++; changeJ = false;
            }
            else{   //Sum < Target
                j++; changeJ = true;
            }
        }

        if(mini == INT32_MAX)    return 0; //No Solution
        else return mini;
    }
};

int main(){
    vector<int> array = {2,3,1,2,4,3};
    Solution find;
    cout << find.findSize(array, 7);
    return 0;
}