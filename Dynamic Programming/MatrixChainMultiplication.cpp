//If a problem can be solved in mutiple patterns yielding same solution: To find the optimal way (min operations required) - MCM Concept. 
//A*B*C --> (A)*(B*C) | (A*B)*(C)

//Find minimum multiplication operations required in matrix multiplication.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int f(int i, int j, vector<int> &array, vector<vector<int>> &dp){
        //Dimension Of Matrix i=1: array[i-1]*array[i]
        if(i==j)    return 0;

        if(dp[i][j]!=-1)    return dp[i][j];
        int mini=1e8;
        for(int k=i; k<j; k++){ //Partition (i, k) & (k+1, j)
            int steps = (array[i-1]*array[j])*array[k] + f(i, k, array, dp) + f(k+1, j, array, dp);
            if(steps<mini)  mini = steps;
        }
        //Multiplying AxBxC x D: A[rows]*D[columns] -> Net Dimension After Multiplication
        //For each field number of multiplications: Columns(C) == Rows(D) == Multiplications
        //Total Multiplications: A[rows]*D[columns] * C[Columns]
        
        return dp[i][j] = mini;
    }

public:
    int minOperations(vector<int> &dimensions){
        int li = dimensions.size()-1;
        vector<vector<int>> dp(li+1, vector<int>(li+1, -1));
        return f(1, li, dimensions, dp);
    }
};

int main(){
    vector<int> dimen = {10,20,30,40};
    Solution newSol;
    cout << newSol.minOperations(dimen);

    return 0;
}