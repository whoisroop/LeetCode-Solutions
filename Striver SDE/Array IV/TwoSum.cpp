// LeetCode - 1. Two Sum.

#include<bits/stdc++.h>
using namespace std;

// Store the elements and check for (target - element), if such a pair is formed to achieve the target.

class Solution {
public:
    vector<int> twoSum(vector<int>& array, int target) {
        int n = array.size();
        unordered_map<int, int> mpp;
        vector<int> pair;
        
        for(int i=0; i<n; i++){
            int findElement = (target - array[i]);
            if(mpp.find(findElement) != mpp.end()){
                //If the element exist: The pair is found.
                int indexA = i;
                int indexB = mpp[findElement];
                pair.push_back(indexA);
                pair.push_back(indexB);
                break;  //As there exists only one solution.
            }
            else    mpp[array[i]]=i;    //Else insert the element & index into the map.
        }

        return pair;
    }
};