#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    double findMedian(vector<int> &arrayA, vector<int> &arrayB){
        //Make sure the size of first array is smaller.
        //If arrayA have 10 element & arrayB have 1 elements: pSize = 6.
        //If we take 0 elements from array A we do not have (6-1) elements in arrayB! Run Time Error!
        if(arrayA.size()>arrayB.size()) return findMedian(arrayB, arrayA);

        int nA = arrayA.size();
        int nB = arrayB.size();
        int pSize = (nA+nB+1)/2;

        int i=0; int j=min(nA, pSize);  //Min & Max Amount Of Elements
        int pA; //Partition Size Of A   : To get a net of partition size number of elements on the left partition.
        int x=0; int y=0;   //To Find: Middle & Middle + 1 Element
        while(i<=j){
            pA = i + (j-i)/2;
            
            int leftA = (pA==0) ? INT32_MIN : arrayA[pA-1]; //No Element On Left : SAFE CASE
            int rightA = (pA==nA) ? INT32_MAX : arrayA[pA]; //All Elements On Left : SAFE CASE

            int pB = (pSize-pA);

            int leftB = (pB==0) ? INT32_MIN : arrayB[pB - 1];
            int rightB = (pB==nB) ? INT32_MAX : arrayB[pB];

            if(leftA<=rightB && leftB<=rightA){
                x = max(leftA, leftB);  //Last Element Of First Part
                y = min(rightA, rightB);    //First Element Of Right Part
                break;
            }

            if(leftA>rightB)    j = pA-1;
            if(leftB>rightA)    i = pA+1;
        }

        if((nA+nB)%2!=0)    return x;
        else    return (x+y)/2.0;
    }

};

int main(){
    vector<int> arrayA = {2};
    vector<int> arrayB = {};
    Solution median;
    cout << median.findMedian(arrayA, arrayB);
    return 0;
}