#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int binarySearch(vector<int> &array, int value){
        int i=0; int j=array.size()-1;

        int mid=0;

        // BinarySearch
        // while(i<=j){
        //     mid = (i+j)/2;  

        //     if(array[mid]==value)   return 1;

        //     if(array[mid]<value)    i=mid+1;
        //     else    j=mid-1;
        // }

        // LowerBound
        // while((j-i)>1){
        //     mid = (i+j)/2;  

        //     if(array[mid]<value)    i=mid+1; //Remove all the elements lesser than the value from search space.
        //     else    j=mid;   //Keep >= values.
        // }

        // if(array[i]>=value)     return i;
        // else if(array[j]>=value)    return j;
        // else    return -1;  //Not Found

        // UpperBound
        // while((j-i)>1){
        //     mid = (i+j)/2;  

        //     if(array[mid]<=value)    i=mid+1;
        //     else    j=mid;
        // }

        // if(array[i]>value)     return i;
        // else if(array[j]>value)    return j;
        // else    return -1;  //Not Found
        
        return -1;
    }
};

int main(){
    vector<int> array = {1,2,3,4,6,6,6,6,6,6,7,9};
    Solution newSol;
    cout << newSol.binarySearch(array, 3);
    return 0;
}