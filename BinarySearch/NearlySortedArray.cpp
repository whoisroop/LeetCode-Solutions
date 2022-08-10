// SEARCH IN A NEARLY SORTED ARRAY:

// Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1]. Write an efficient function to search an element in this array. Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].

// For example consider the array {2, 3, 10, 4, 40}, 4 is moved to next position and 10 is moved to previous position.

// Example :
// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
// Output: 2 (INDEX)
#include<iostream>
#include<vector>
using namespace std;

//The question is similar to binary search except the fact that instead of middle the element might be present in middle-1, middle or middle+1. However, all the elements left of middle will be smaller than middle & all the elements right of middle will be greater than middle: Binary Search.

class Solution{
public:
    int find(vector<int> &array, int value){
        int i=0; int j=array.size()-1;
        int midpoint;

        while(i<=j){
            midpoint = i + (j-i)/2;
            // cout << midpoint << " | " << array[midpoint] << endl; 
            if(value==array[midpoint]) return midpoint;
            if((midpoint-1)>=i && value==array[midpoint-1]) return midpoint-1;
            if((midpoint+1)<=j && value==array[midpoint+1]) return midpoint+1;

            if(array[midpoint]<value) i=midpoint+2;
            else j=midpoint-2;
        }

        return -1;
    }
};

int main(){
    vector<int> array = {10, 3, 40, 20, 50, 80, 70};
    Solution find;
    cout << find.find(array, 70);
}