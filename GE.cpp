#include<bits/stdc++.h>
using namespace std;

// 2.    Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. The function should find all triplets in the array that sum up to the target sum and return a two-dimensional array of all these triplets. If no three numbers sum up to the target sum, the function should return an empty array.
// a.    Sample input: [12, 3, 1, 2, -6, 5, -8, 6], 0
// b.    Sample output: [[-8, 2, 6], [-8, 3, 5], [-6, 1, 5]]

// -8 -6 1 2 3 5 6 12
// A + B + C = T
// B + C = T - A
// B + C = 8
class Solution{
private:
public: //O(N^2)
    vector<vector<int>> threesum(vector<int> A, int target){
        int N = A.size();
        sort(A.begin(), A.end());   // N Log N

        vector<vector<int>> solution;
        for(int ia=0; ia<N; ia++){  // N
            int ib = ia+1; int ic = N-1;
            int nt = target - A[ia];    // B + C = (T - A)

            while(ib < ic){ // N
                int sum = A[ib] + A[ic];

                if(sum == nt){
                    solution.push_back({A[ia], A[ib], A[ic]});
                    ib += 1; ic -= 1;
                }
                if(sum < nt) ib += 1;
                else ic -= 1;
            }
        }

        for(int i=0; i<solution.size(); i++){
            for(int j=0; j<3; j++) cout << solution[i][j] << " ";
            cout << endl;
        }

        return solution;
    }
};

int main(){
    Solution solve;
    vector<int> A = {12, 3, 1, 2, -6, 5, -8, 6};
    solve.threesum(A, 0);
    return 0;
}