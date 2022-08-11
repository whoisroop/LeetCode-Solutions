//Find the element lesser than or equal to the given value.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int floor(vector<int> &array, int value){
        int i=0; int j=array.size()-1;
        int midpoint;

        int index=-1;
        while(i<=j){
            midpoint = i + (j-i)/2;

            if(array[midpoint]==value){
                index = midpoint;
                j = midpoint-1; //Search for more occurences on left
            }
            else if(array[midpoint]<value){
                index=midpoint;
                i = midpoint+1;
            }
            else{
                j = midpoint-1;
            }
        }

        return index;
    }
};