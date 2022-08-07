#include<iostream>
#include<vector>
using namespace std;

//Array: 4 5 6 7 0 1 2 3
//No matter which index, one of left or right part will be sorted.
//Check if the element exists in the sorted part range.
//If not remove the indexes from search space.  (Lower Bound Concept: 4 5 6 7 7 0 3 3: Find 7 - 3)
class Solution{
public:
    int findElement(vector<int> &array, int value){
        int i=0; int j=array.size()-1;
        int mid;

        //Lower Bound Is Upper Bound Of Value-1
        while(i<=j){
            mid = i + (j-i)/2;
            if(array[mid]==value)    return mid;    //Distinct Elements

            if(array[i]<=array[mid]){   //Left Part Sorted
                //Check if value lies in the left part.
                if(array[i] <= value && value <= array[mid])    j = mid-1;  
                else    i = mid+1;
            }
            else{   //Right Part Sorted
                //Check if the value lies in the right part.
                if(array[mid] <= value && value <= array[j])    i = mid+1;
                else    j = mid-1;
            }
        }

        return i;
    }
};

int main(){
    vector<int> array = {4,5,6,7,0,1,2};
    Solution find;
    cout << find.findElement(array, 0);
}