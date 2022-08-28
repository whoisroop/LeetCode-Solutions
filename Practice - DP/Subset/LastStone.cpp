//LeetCode 1049 - Last Stone Weight II.
// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have array x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the smallest possible weight of the left stone. If there are no stones left, return 0.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    //Find the min difference subset.
    int findLastStone(vector<int> array){
        int n = array.size();
        int sum=0;
        for(int &i: array) sum+=i;
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));

        for(int i=0; i<n; i++) dp[i][0]=1;
        if(array[0]<=sum) dp[0][array[0]]=1;

        for(int index=1; index<n; index++){
            for(int target=1; target<=sum; target++){
                bool take = false;
                if(target>=array[index]) take = dp[index-1][target-array[index]];
                bool notTake = dp[index-1][target];

                dp[index][target] = (take||notTake);
            }
        }

        cout << "DP";
        for(int i=0; i<=sum; i++) cout << dp[n-1][i] << " ";

        //DP[n-1][] --> Indicates all the achievable values of the subsets that can be formed.

        int minDifference=INT32_MAX;
        int midpoint = (sum/2); if(sum%2!=0) midpoint++;
        for(int i=0; i<=midpoint; i++){
            if(dp[n-1][i]==1){
                cout << i << " " << (sum-i) << endl;
                minDifference = min(minDifference, abs(i - (sum-i)));
            }        
        }

        return minDifference;
    }

};

int main(){
    vector<int> array = {31,26,33,21,40};
    Solution find;
    cout << find.findLastStone(array);
    return 0;
}