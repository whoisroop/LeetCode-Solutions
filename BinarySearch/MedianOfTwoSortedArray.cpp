#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution{
public:
    int upperBound(vector<int> &array, int value){
        int i=0; int j=array.size()-1;
        int mid;

        while(i<=j){
            mid = i + (j-i)/2;

            if(array[mid]<=value)   i=mid+1;
            else    j=mid-1;
        }

        return i;
    }

    double findMedian(vector<int> &arrayA, vector<int> &arrayB){
        int nA = arrayA.size();
        int nB = arrayB.size();

        int i=min(arrayA[0], arrayB[0]); int j=(max(arrayA[nA-1], arrayB[nB-1]));
        int mid;
        int value = ((nA+nB)%2==0) ? ((nA+nB)/2) - 1 : ((nA+nB)/2);
        if(value<i) return i;
        while(i<=j){
            mid = i + (j-i)/2;

            int leq = upperBound(arrayA, mid) + upperBound(arrayB, mid);
            //Find Elements In Arrays Lesser Than Equal To Mid Value.

            if(leq<=value)    i = mid+1;
            else    j = mid-1;
        }

        int x = i;
        int y = x;
        if((nA+nB)%2 ==0 ){
            // (j = min(upperBound(arrayA, x), upperBound(arrayB, x)));
            int a = upperBound(arrayA, x);
            int b = upperBound(arrayB, x);
            if(a<nA && b==nB)   y = arrayA[a];
            if(b<nB && a==nA)   y = arrayB[b];

            if(a==nA && b==nB)   y = x;
            if(a<nA && b<nB)    y = min(arrayA[a], arrayB[b]);
        }

        cout << (x+y)/2.0;
        return (x+y)/2.0;
    }

};

int main(){
    vector<int> arrayA = {0,0};
    vector<int> arrayB = {0,0};
    Solution median;
    median.findMedian(arrayA, arrayB);
    return 0;
}