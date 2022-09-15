//LeetCode - 1262. Greatest Sum Divisible By Three.
//Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public: 
    //TLE
    int findSubsetSum(vector<int> &array){
        int n = array.size();
        int sum=0; for(const int &i: array) sum+=i;
        vector<int> p(sum+1, 0), c(sum+1, 0);
        
        //BaseCase:
        p[0]=1; c[0]=1;
        if(array[0]<=sum) p[array[0]] = 1;

        for(int index=1; index<n; index++){
            p[0]=1; c[0]=1;
            for(int target=1; target<=sum; target++){
                bool take=false;
                if(target>=array[index]) take = p[target-array[index]];
                bool notTake = p[target];

                c[target] = (take||notTake);
            }
            
            p = c; //Previous = Current
        }

        for(int target=sum; target>=0; target--){
            if(target%3==0 && p[target]==1) return target;
        }

        return 0;
    }
};

int main(){
    vector<int> array = {1,2,3,4,4};
    Solution find;
    cout << find.findSubsetSum(array);
    return 0;
}