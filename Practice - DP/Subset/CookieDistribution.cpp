//LeetCode - 2305. Fair Distribution Of Cookies.
//You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.
// The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.
// Return the minimum unfairness of all distributions.

#include<iostream>
#include<vector>
using namespace std;

//The concept used here is to select a number & put it into a bucket (subset).
//Total bucket (subsets) = K.
//A new element can be added to the existing subsets or can form a new subset.
//Only add the element to the first empty subset out of all empty subsets to avoid identical subsets formation.
//Use a count variable to count the filled subsets. (Later to check if all the subsets are filled.)
//The vector subset contains subset sum of each subset. When (index<0) find the maximum subset sum.
//Among all the maximum subset sum find the minimum! - Among all the distributions find minimum of maximum subset sums.

class Solution{
public:
    void divide(int index, int count, int k, vector<int> &subset, vector<int> &array, int &mini){
        if(index<0){
            if(count==k){   //The partition is done into all the subsets.
                int maxi=0;
                for(int &i: subset) maxi = max(maxi, i);
                mini = min(mini, maxi);
            }
            return;
        }

        for(int i=0; i<k; i++){
            if(subset[i]>0){
                subset[i]+=array[index];
                divide(index-1, count, k, subset, array, mini);
                subset[i]-=array[index];
            }
            else{   //Empty Subset - Add to the first empty subset.
                subset[i]+=array[index];
                divide(index-1, count+1, k, subset, array, mini);
                subset[i]-=array[index];
                break;
            }
        }

        return;
    }

    int findUnfairness(vector<int> &array, int k){
        int n = array.size();
        vector<int> subset(k, 0);
        int mini=1e9;

        //Count is not needed for current problem.
        divide(n-1, 0, k, subset, array, mini);
        return mini;
    }

};

int main(){
    vector<int> array = {8,15,10,20,8}; //2

    Solution find;
    cout << find.findUnfairness(array, 2);
    return 0;
}