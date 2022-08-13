#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int findPeak(vector<int> &array){
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
        
        return -1;  //No Peak Exists
    }

    int binary(vector<int> &array, int i, int j, int value){   //Increasing Order
        int midpoint;

        while(i<=j){
            midpoint = i + (j-i)/2;

            if(array[midpoint]==value)  return midpoint;
            else if(array[midpoint]>value) j=midpoint-1;
            else i=midpoint+1;
        }

        return -1;  //No Solution
    }

    int binaryR(vector<int> &array, int i, int j, int value){    //Decreasing Order
        int midpoint;

        while(i<=j){
            midpoint = i + (j-i)/2;

            if(array[midpoint]==value)  return midpoint;
            else if(array[midpoint]>value) i=midpoint+1;
            else j=midpoint-1;
        }

        return -1;  //No Solution
    }

public:
    int findElement(vector<int> &array, int value){
        int peak = findPeak(array);
        if(array[peak]==value)  return peak;

        if(value >= array[0] && value <= array[peak-1]){    //Value lies in ascending part.
            int index = binary(array, 0, peak-1, value);
            if(index==-1)   return -1;
            else return index;
        }
        else{   //Value lies in descending part.
            int index = binaryR(array, peak+1, array.size()-1, value);
            if(index==-1)   return -1;
            else return index;
        }

        return -1;
    }
};

int main(){
    vector<int> array = {3,5,3,2,0};
    Solution find;
    cout << find.findElement(array, 5);
    return 0;
}