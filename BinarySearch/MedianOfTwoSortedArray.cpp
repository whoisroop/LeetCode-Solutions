#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    double findMedian(vector<int> &arrayA, vector<int> &arrayB){
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

            int leftB = ((pSize-pA)==0) ? INT32_MIN : arrayB[(pSize-pA) - 1];
            int rightB = ((pSize-pA)==nB) ? INT32_MAX : arrayB[(pSize-pA)];

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
    vector<int> arrayA = {1,7};
    vector<int> arrayB = {3,6};
    Solution median;
    cout << median.findMedian(arrayA, arrayB);
    return 0;
}