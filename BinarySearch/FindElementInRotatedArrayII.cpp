#include<iostream>
#include<vector>
using namespace std;

//PART 2:
//Array: 4 4 6 7 0 1 3 3    NON DISTINCT ELEMENTS
//No matter which index, one of left or right part will be sorted.
//Check if the element exists in the sorted part range. 
//If not remove the indexes from search space.
// NEXT QUESTION :  (Lower Bound Concept: 4 5 6 7 7 0 3 3: Find 7 - 3)
class Solution{
public:
    bool findElement(vector<int> &array, int value){
        int i=0; int j=array.size()-1;
        int mid;

        //Lower Bound Is Upper Bound Of Value-1
        while(i<=j){
            mid = i + (j-i)/2;

            if(array[mid]==value)   return true;

            //Extra Condition
            //Shrink the search space if array[i] = array[mid] = array[j] : 1 0 1 1 1 (FIND 0)
            //We won't be able to tell which side is sorted
            if(array[i]==array[mid] && array[j]==array[mid]){ i++; j--; continue;}

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

        return false;
    }
};

int main(){
    vector<int> array = {1,0,1,1,1};
    Solution find;
    cout << find.findElement(array, 0);
}