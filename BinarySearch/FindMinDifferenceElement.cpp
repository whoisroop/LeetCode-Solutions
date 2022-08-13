//Find the element that has minimum absolute difference of the given key.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int lowerBound(vector<int> &array, int value){
        int i=0; int j=array.size()-1;
        int midpoint;

        //Code to find upperbound:
        while(i<=j){
            midpoint = i + (j-i)/2;

            if(array[midpoint] >= value) j=midpoint-1;
            else i=midpoint+1;   
        }

        return i;
    }

    int upperBound(vector<int> &array, int value){
        return lowerBound(array, value+1);  //Upper Bound -> Lower Bound Of Value + 1
    }

public:
    int findIndex(vector<int> &array, int key){
        int ubound = upperBound(array, key);  
        int lbound = lowerBound(array, key);  

        if(array[lbound]==key) return lbound; //If key is present: LowerBound = Key
        
        lbound = lbound-1;  //If key not present go to next smaller element.

        cout << "UPPER: " << ubound << " | " << "LOWER: " << lbound << endl;

        if(abs(key - array[lbound]) <= abs(key - array[ubound])) return lbound;
        else return ubound;
    }

};

int main(){
    vector<int> array = {1,2,3,3,4,9};
    Solution find;
    cout << find.findIndex(array, 3);
    return 0;
}