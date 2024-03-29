// LeetCode: 3Sum.
// Description: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
// Approach: 

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
public:
    vector<vector<int>> threeSum(vector<int> &A){
        sort(A.begin(), A.end());
        int N = A.size();
        vector<vector<int>> solution;

        // A + B + C = 0
        // B + C = -A
        // All Triplets
        for(int i=0; i<N; i++){
            if(i != 0 && A[i] == A[i-1]) continue;
            vector<int> triplet(3, 0);

            int tsum = -1*A[i];
            int p = i+1, q = N-1;
            while(p<q){
                int sum = A[p] + A[q];
                if(sum == tsum){
                    // No such pair should repeat:
                    while(p<q && A[p] == A[p+1]) p += 1;    // Skip the duplicates.
                    while(p<q && A[q] == A[q-1]) q -= 1;

                    // We're at the edge of values ( 1 (p: 1) (q: 3) 3 3):
                    triplet[0] = A[i];
                    triplet[1] = A[p];
                    triplet[2] = A[q];

                    solution.push_back(triplet);
                    p += 1; q -= 1;
                }
                else if(sum < tsum) p += 1;
                else q -= 1;
            }
        }

        cout << "SOLUTION: " << endl;
        for(auto i: solution){
            for(int j: i) cout << j << " ";
            cout << endl;
        }

        return solution;
    }

    // vector<vector<int>> threeSum(vector<int> &A){
    //     sort(A.begin(), A.end());
    //     int N = A.size();
    //     set<vector<int>> result;

    //     // A + B + C = 0
    //     // B + C = -A
    //     // All Triplets
    //     for(int i=0; i<N; i++){
    //         vector<int> triplet(3, 0);

    //         int tsum = -1*A[i];
    //         unordered_map<int, int> fmap;
    //         for(int j=i+1; j<N; j++){
    //             int search = tsum - A[j];
    //             if(fmap.count(search) != 0){
    //                 fmap[search] -= 1;
    //                 if(fmap[search] == 0) fmap.erase(search);

    //                 triplet[0] = A[i];
    //                 triplet[1] = search;
    //                 triplet[2] = A[j];
    //                 for(int i: triplet) cout << i << " ";
    //                 cout << endl;
    //                 result.insert(triplet);
    //             }
    //             else{ fmap[A[j]] += 1; }
    //         }
    //     }

    //     vector<vector<int>> solution(result.begin(), result.end());
    //     return solution;
    // }
};

int main(){
    Solution solve;
    vector<int> T = {-2,-1,0,1,1,2,2};
    solve.threeSum(T);
    return 0;
}