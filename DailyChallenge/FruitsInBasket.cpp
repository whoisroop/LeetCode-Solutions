// LeetCode - 904. Fruit Into Baskets
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int> &A) {
        int n = A.size();

        unordered_map<int, int> fmap;   //Frequency Map
        int i=0, j=0;
        int max_fruits = 0;
        int counter = 0;
        while(j < n){
            fmap[A[j]] += 1; counter += 1;

            while(fmap.size() > 2){
                fmap[A[i]] -= 1; counter -= 1;
                
                if(fmap[A[i]] == 0) fmap.erase(fmap.find(A[i]));
                i += 1;
            }

            max_fruits = max(max_fruits, counter);
            j += 1;
        }

        return max_fruits;
    }
};

int main(){
    Solution solve;
    
    return 0;
}