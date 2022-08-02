#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    bool isPalindrome(string &s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }

        return true;
    }

    int f(int i, int j, string &s, vector<int> &dp){
        if(i==j+1)    return 0;

        if(dp[i]!=-1)   return dp[i];
        
        string x;   //Overall String Selected
        int partition = 0;
        int mini = 1e9;
        for(int p=i; p<=j; p++){
            x+=s[p];
            if(isPalindrome(x)){
                partition = 1 + f(p+1, j, s, dp);
                if(partition<mini)  mini = partition;
            }
        }

        return dp[i] = mini;
    }

public:
    int minPartitions(string &s){
        int l = s.size();
        vector<int> dp(l, -1);
        return f(0, l-1, s, dp)-1;
    }

    

};

int main(){
    string s = "abacbabcefe";
    Solution newSol;
    cout << newSol.minPartitions(s);
    return 0;
}