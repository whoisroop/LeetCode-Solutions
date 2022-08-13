#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //The value increases to a certain index then decreases.
    //If midpoint is a part of increasing index move right else move left.
    int peakIndexInMountainArray(vector<int>& array) {
        int i=0; int j=array.size()-1;
        int midpoint;
        
        int li = array.size()-1;
        while(i<=j){
            midpoint = i + (j-i)/2;
            
            if(midpoint==0 || midpoint==li){
                if(midpoint==0) return 1;
                else return li-1;
            }

            if(array[midpoint-1]<array[midpoint] && array[midpoint]>array[midpoint+1])  return midpoint;
            else if(array[midpoint]>array[midpoint-1] && array[midpoint]<array[midpoint+1]) i=midpoint+1; //Increasing
            else j=midpoint-1;  //Decreasing
        }
        
        return -1;  //No Solution Exists
    }
};

int main(){
    vector<int> array = {3,5,3,2,0};
    Solution find;
    cout << find.peakIndexInMountainArray(array);
    return 0;
}