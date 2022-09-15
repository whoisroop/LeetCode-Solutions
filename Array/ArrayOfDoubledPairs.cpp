//LeetCode - 954. Array of doubled pairs.
//Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.

#include<bits/stdc++.h>
using namespace std;

bool comparator(const int &x, const int &y){
    if(x<0 && y<0){
        return (x>y);
    }
    else return (x<y);
}

class Solution {
public:
    bool canReorderDoubled(vector<int>& array) {
        int n = array.size();
        if(n%2!=0) return false;
        
        unordered_multiset<int> mset;
        sort(array.begin(), array.end(), comparator);

        for(const int &i: array){
            if(i%2==0 && mset.find(i/2)!=mset.end()){
                mset.erase(mset.find(i/2)); //Pair Found - Erase
            }
            else mset.insert(i);
        }
        
        return (mset.empty());
    }
};

int main(){
    vector<int> array = {4,-2,2,-4};  // 1 2 2 2 4 4
    Solution find;
    cout << find.canReorderDoubled(array);
    return 0;
}