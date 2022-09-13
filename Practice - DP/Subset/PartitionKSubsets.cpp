//LeetCode - 698. Partition to K Equal Sum Subsets.
//Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

//LeetCode - 473. Matchsticks to square.
//You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
//Return true if you can make this square and false otherwise.
//Partition given set into 4 equal sum subsets.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Aim is to find if there exists k distinct subsets each with sum equal to target with no repeating elements in different subsets.
    //In order to tackle repeating elemenets, use a visited array to keep the track of already selected elements.
    //Traverse through each element: Pick or Not Pick. Pick if the subset sum < target & Not Pick otherwise.
    //If the required subset sum is achieved: Recursively call the function again to find another set of elements that yeilds target sum & pass the visited array as argument.
    //For each subset sum found decrease the subset counter (k).

    bool find(int index, int sum, int target, int k, vector<int> &visited, vector<int> &array){
        if(k==0) return true;
        //If one subset sum is satisfied: Decrease count of k & find another (k-1) subsets to yeild the target sum.
        if(sum==target) return find((array.size()-1), 0, target, k-1, visited, array);
        if(index<0) return false;

        bool take = false;
        if((array[index]+sum)<=target && visited[index]!=1){
            visited[index]=1;
            take = find(index-1, sum+array[index], target, k, visited, array);
            if(take==true) return true;
            visited[index]=0;
        }
        bool notTake = find(index-1, sum, target, k, visited, array);

        return (take||notTake);
    }

    bool canPartition(vector<int> &array, int k){
        int n=array.size();
        int sum=0; 
        for(const int &i: array) sum+=i;
        if(sum%k!=0) return false;

        sort(array.begin(), array.end());
        vector<int> visited(n, 0);

        return find(n-1, 0, (sum/k), k, visited, array);
    }
};

int main(){
    vector<int> array = {4,5,9,3,10,2,10,7,10,8,5,9,4,6,4,9};
    Solution find;
    cout << find.canPartition(array, 5);
    return 0;
}