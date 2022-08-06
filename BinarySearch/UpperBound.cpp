#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int upperBound(vector<int> &array, int value){
        int i=0, j=array.size()-1;
        int mid;
        while(i<=j){
            mid = i + (j-i)/2;

            if(array[mid]<=value)   i = mid+1;
            else    j = mid-1;
        }

        return i;
    }

    int lowerBound(vector<int> array, int value){   //Lower Bound Is The UpperBound Of (Value-1)
        return upperBound(array, value-1);
    }
};

int main(){
    vector<int> array = {2,4,5,7,7,9,11,11,11,11,13,16,17,17};
    Solution bound;
    for(int i:array)    if(bound.lowerBound(array, i) != lower_bound(array.begin(), array.end(), i)-array.begin())   cout << "FALSE : " << i << endl;
    int ub = bound.upperBound(array, 4); 
    cout << "UPPER BOUND: " << ub << endl;
    int lb = bound.lowerBound(array, 1);
    cout << "LOWER BOUND: " << lb << endl;

    return 0;
}