#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool isPossible(vector<int> &array){
        int lastIndex = array.size()-1;
        vector<int> dp(lastIndex+1, 0);

        dp[lastIndex] = 1;

        bool isPossible;
        for(int i=lastIndex-1; i>=0; i--){
            isPossible = false;
            for(int j=1; j<=array[i]; j++){
                if((i+j)<=lastIndex) isPossible = (isPossible || dp[i+j]);
                if(isPossible == true)  break;
            }

            dp[i] = isPossible;
        }

        return dp[0];
    }


};

int main(){
    vector<int> array = {3,2,1,1,4,1};
    Solution newSol;
    cout << newSol.isPossible(array);

    return 0;
}
