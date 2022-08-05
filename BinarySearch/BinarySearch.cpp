#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool binarySearch(vector<int> &array, int value){
        int i=0, j=(array.size()-1);
        int mid = 0;
        while((j-i)>1){
            mid = (i+j)/2;

            if(array[mid]<=value)    i=mid;
            else    j=mid-1;
        }
        if(array[i]==value || array[j]==value)  return true;
        else    return false;
    }

    int lowerBound(vector<int> &array, int value){
        int i=0, j=(array.size()-1);
        int mid = 0;
        while((j-i)>1){
            mid = (i+j)/2;

            if(array[mid]<value)    i=mid+1;    //Search space removes all the elements < value
            else    j=mid;  //Search space contains all the elements >= value
        }

        if(array[i]>=value) return i;
        else if(array[j]>=value) return j;
        else return -1;
    }

    int upperBound(vector<int> &array, int value){
        int i=0, j=(array.size()-1);
        int mid=0;
        while((j-i)>1){
            mid = (i+j)/2;
            
            if(array[mid]<=value)   i=mid+1;    //Search space removed all the elements <= value
            else    j=mid;  //Seach space contains all the elements < value
        }

        if(array[i]>value) return i;
        else if(array[j]>value) return j;
        else return -1;
    }

};

int main(){
    vector<int> array = {1,2,3,5,7,9,9,9,11,11};
    Solution binary;

    cout << "BINARY SEARCH: " << binary.binarySearch(array, 4) << endl;
    cout << "LOWER BOUND: " << binary.lowerBound(array, 9) << endl;
    cout << "UPPER BOUND: " << binary.upperBound(array, 11) << endl;
    return 0;
}