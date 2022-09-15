//LeetCode - 2007. Find Original Array From Doubled Array.
//An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findOriginal(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        int n = changed.size();
        vector<int> original;
        unordered_multiset<int> mset;
        
        if(n%2!=0) return original;
        
        //The array is iterated in ascending order.
        //For every element in the array check if there exists (ELEMENT/2) in the multiset.
        //If there exists, We found a pair (ELEMENT & (ELEMENT/2)) : Insert (ELEMENT/2) into the original array.
        //Otherwise insert ELEMENT into the multiset, we'll hope to find (2xELEMENT) while iterating further to the greater elements of the array.
        
        for(const int &i: changed){
            if(i%2==0 && mset.find(i/2)!=mset.end()){
                //ELEMENT & ELEMENT/2 pair found!
                //Insert ELEMENT/2 into original array & remove it from the multiset as a pair is formed.
                original.push_back(i/2);
                mset.erase(mset.find(i/2));
            }
            else{
                mset.insert(i);
            }
        }

        //Solution:
        for(int i: original) cout << i << " ";
        
        if(original.size() == (n/2)) return original;
        else{
            vector<int> empty;
            return empty;
        }
    }
};

int main(){
    vector<int> array = {2,1,2,4,2,4};  // 1 2 2 2 4 4
    Solution find;
    find.findOriginal(array);
    return 0;
}