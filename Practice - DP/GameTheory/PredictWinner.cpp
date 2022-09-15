//LeetCode - 486. Predict The Winner. || LeetCode - 877. Stone Game. 
// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.
// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    //GAME THEORY:
    //Played from player A perspective: To win the game pA need to maximize his score or minimize pB score.
    //Similarly from player B perspective: To win the game pB need to maximize his score or minimize pA score.
    //PLAYER A POV - 
    //When its pA's turn - Choose the option that maximizes pA's score.
    //When its pB's turn - Choose the option that minimizes pA's score.
    //As the function keeps track of & returns pA's score only.
    //When it's pA's turn add the score & for pB's turn do not add to the score (pA's score) but make the choice.

    //PARAMETERS:
    //i & j : Ends of the array.
    //turn : 1 If turn of player A. 0 If turn of player B.
    int find(int i, int j, bool turn, vector<int> &array, vector<vector<vector<int>>> &dp){
        if(i>j) return 0;

        if(dp[i][j][turn]!=-1) return dp[i][j][turn]; 

        //PLAYER A: Maximize the score of player A.
        if(turn){
            int pathA = array[i] + find(i+1, j, 0, array, dp);
            int pathB = array[j] + find(i, j-1, 0, array, dp);
            return dp[i][j][turn] = max(pathA, pathB);
        }

        //PLAYER B: Minimize the score of player A.
        else{
            int pathA = find(i+1, j, 1, array, dp);
            int pathB = find(i, j-1, 1, array, dp);
            return dp[i][j][turn] = min(pathA, pathB);
        }
        
    }

    bool predictWinner(vector<int> &array){
        int i=0; int j=array.size()-1;
        int n = array.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        int pA = find(i, j, 1, array, dp);

        int total=0; for(const int &i: array) total+=i;
        int pB = total - pA;

        return (pA>=pB);
    }
};

int main(){
    vector<int> array = {1,5,2};
    Solution find;
    cout << ((find.predictWinner(array))? "TRUE":"FALSE") << endl;
    return 0;
}