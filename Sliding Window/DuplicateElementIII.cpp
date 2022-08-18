#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool findAlmostDuplicate(vector<int> &array, int k, int t){
        int i=0; int j=0;
        int window = k+1;
        
        multiset<long int> mset;
        int n = array.size();
        
        if(window<2) return false; //Distinct indexes.
        //EXAMPLE: array[j]=9, t=3 : The element will lie in the range of 9-3 & 9+3
        //Find the smallest integer greater than 9-3 via lower bound & check if that is smaller than 9+3 if not then there's no solution.
        while(j<n){
            cout << i << " " << j << endl;
            mset.insert(array[j]);

            // -t <= array[j] - x (array[i]) <= t
            // array[j] - x <= t --> x >= array[j] - t FIND LOWER BOUND OF ARRAY[J] - T
            // Obtained x via lower bound is the smallest integer that satisfies the condition.
            //Now apply the second condition: x <= array[j] + t : MAKES SENSE
            auto x = mset.lower_bound(1LL*array[j]-t);
            if(x == mset.find(array[j])) x++; //Avoid getting the same element as we need distinct i, j.
            if(x!=mset.end() && *x <= (1LL*array[j]+t)){
                cout << "SELECTED: " << *x << endl;
                return true;
            }
            
            if((j-i+1)<window) j++;
            else{   //Window formed.
                mset.erase(mset.find(array[i]));
                i++; j++;
            }
        }
        
        return false;
    }
    
};

int main(){
    vector<int> array = {1,2,3,1};
    Solution find;
    cout << find.findAlmostDuplicate(array,3,0);
    return 0;
}