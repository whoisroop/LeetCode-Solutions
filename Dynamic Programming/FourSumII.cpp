#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
    int fourSumCount(vector<int> &arrayA, vector<int> &arrayB, vector<int> &arrayC, vector<int> &arrayD){
        //a+b+c+d = 0
        //a+b = -(c+d) || c+d = -(a+b)
        int count = 0;
        unordered_map<int, int> mpp;    //Sum To Frequency

        //Insert all the possible sums of a+b.
        for(int &i: arrayA){
            for(int &j: arrayB){
                mpp[(i+j)]++;
            }
        }

        //Find if there exists -(c+d) in the hashmap.
        //If exists increase the count by frequency of that sum.
        for(int &i: arrayC){
            for(int &j: arrayD){
                if(mpp.find(-(i+j)) != mpp.end()){
                    count = count + mpp[-(i+j)];
                }
            }
        }

        return count;
    }

};

int main(){
    Solution newSol;
    vector<int> arrayA = {0,1,-1};
    vector<int> arrayB = {-1,1,0};
    vector<int> arrayC = {0,0,1};
    vector<int> arrayD = {-1,1,1};
    cout << newSol.fourSumCount(arrayA, arrayB, arrayC, arrayD);
}