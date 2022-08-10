//Find Minimum Value In Rotated Sorted Array
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& array) {
        int i=0; int j=array.size()-1;
        int midpoint;
        int mini = INT32_MAX;
        while(i<=j){
            midpoint = i + (j-i)/2;
            
            //Save Minimum In Sorted Part & Continue Search In Other Part. 
            if(array[i]<=array[midpoint]){  //Left Part Sorted
                mini = min(mini, array[i]);
                i = midpoint+1;
            }
            else{
                mini = min(mini, array[midpoint]);  //Right Part Sorted
                j = midpoint-1;
            }
            
        }
        
        return mini;
    }
};

int main(){
    vector<int> array = {3,4,5,1,2};
    Solution find;
    cout << find.findMin(array);
}