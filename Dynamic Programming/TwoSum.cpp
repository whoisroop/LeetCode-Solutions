#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> reference = nums;
        sort(nums.begin(), nums.end());
        int a=0, b=nums.size()-1;
        vector<int> index;
        int sum = 0;
        while(true){
            sum = nums[a]+nums[b];
            if(sum==target){
                index.push_back(nums[a]);
                index.push_back(nums[b]);
                break;
            }
            else if(sum<target) a++;
            else b--;
        }
        
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<index.size(); j++){
                if(index[j]==reference[i]){
                    index[j]=i;
                    break;
                }
            }
        }
        
        return  index; 
    }
};