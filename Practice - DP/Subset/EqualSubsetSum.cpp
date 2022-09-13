//LeetCode - 416. Partition Equal Subset Sum
//Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

#include<iostream>
#include<vector>
using namespace std;

//DP[index][value]: The value tells if it is possible to attain a subset sum of 'value' using the the first index (0 1 2 ... index) elements of array.

class Solution{
private:
    bool find(int index, int target, vector<int> &array, vector<vector<int>> &dp){
        if(target==0) return true;
        if(index==0){
            if(target==array[0]) return true;
            else return false;
        }

        if(dp[index][target]!=-1) return dp[index][target];

        bool take = false;
        if(target>=array[index]) take = find(index-1, target-array[index], array, dp);
        if(take==true) return true;

        bool notTake = find(index-1, target, array, dp);
        if(notTake==true) return true;

        return dp[index][target] = (take||notTake);
    }

public:
    bool findIfPossible(vector<int> &array){
        int n = array.size();
        if(n<2) return false;
        int sum=0;
        for(const int &i: array) sum+=i;
        if(sum%2!=0) return false;
        int target = sum/2;

        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return find(n-1, target, array, dp);
    }
};

int main(){
    vector<int> array = {1,5,11,1};
    Solution find;
    cout << find.findIfPossible(array);
    return 0;
}