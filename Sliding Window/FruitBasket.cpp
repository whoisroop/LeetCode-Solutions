//LeetCode - 904 Fruit Into Basket.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits, int k) {
        int i=0; int j=0;
        int n = fruits.size();
        unordered_map<int, int> mpp;
        int maxi = 0;
        
        //Find max length substring with 2 distinct elements.
        if(n<=k) return n;
        while(j<n){
            mpp[fruits[j]]++;
            
            if(mpp.size()>k){
                while(mpp.size()>2){
                    mpp[fruits[i]]--;
                    if(mpp[fruits[i]]==0)   mpp.erase(mpp.find(fruits[i]));
                    i++;
                }
                j++;
            }
            else if(mpp.size()<=k){
                maxi = max(maxi, (j-i+1));
                j++;
            }
        }
        
        return maxi;
    }
};

int main(){
    vector<int> array = {1,1,2,3,4,3,4};
    Solution find;
    cout << find.totalFruit(array, 2);
}