//LeetCode 115: Find the occurences of stringB in stringA.
#include<iostream> 
#include<vector>
using namespace std;

class Solution{
public:
    int find(string &sa, string &sb, int ia, int ib, vector<vector<int>> &dp){
        if(ib==-1) return 1;   //Single Occurence Of String B Found.
        if(ia<0) return 0;  //String A Exhausted: No Occurence Found.
        if(ia<ib) return 0; //TO MAKE THE PROGRAM FASTER! When size of string B > string A : no occurence will be found.

        if(dp[ia][ib]!=-1)  return dp[ia][ib];

        int sum=0;
        //If the character matches:
        if(sa[ia]==sb[ib]){
            int take = find(sa, sb, ia-1, ib-1, dp);
            int notTake = find(sa, sb, ia-1, ib, dp);

            sum = take + notTake;
        }
        //If the character not matches:
        else{
            int notTake = find(sa, sb, ia-1, ib, dp);  //NotTake Case

            sum = notTake;
        }

        return dp[ia][ib] = sum;
    }

    int findOccurence(string sa, string sb){
        int la = sa.size(); int lb = sb.size();
        vector<vector<int>> dp(la, vector<int>(lb, -1));
        return find(sa, sb, la-1, lb-1, dp);
    }
};

int main(){
    string sa = "rabbbit";
    string sb = "rabbit";
    Solution find;
    cout << find.findOccurence(sa, sb);
    return 0;
}
