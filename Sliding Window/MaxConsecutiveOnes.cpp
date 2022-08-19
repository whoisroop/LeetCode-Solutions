//LeetCode - 1004. Maximum Consecutive Ones
//Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //Find max subarray size with atmost k zeroes
    int longestOnes(vector<int> &array, int k) {
        int i=0; int j=0;
        vector<int> f(2,0); //Store frequency
        int maxi = 0;
        
        int n = array.size();
        while(j<n){
            f[array[j]]++;
            
            if(f[0]<k){
                maxi = max(maxi, (j-i+1));
                j++;
            }
            else{
                while(f[0]>k){
                    f[array[i]]--;
                    i++;
                }
                maxi = max(maxi, (j-i+1));
                j++;
            }
        }
        
        return maxi;
    }
};

int main(){
    vector<int> array = {1,1,1,0,0,0,1,1,1,1,0};
    int flips = 2;
    Solution find;
    cout << find.longestOnes(array, flips);
    return 0;
}