#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& array, int val) {
        int i=0, j=array.size()-1;
        
        while(i<=j){
            if(array[i]==val){
                while(j>0 && array[j]==val) j--;
                if(j<=i) return i;
                else{
                    array[i] = array[i]+array[j];
                    array[j] = array[i]-array[j];
                    array[i] = array[i]-array[j];
                }
            }
            
            i++;
        }
        
        return i;
    }
};

int main(){
    vector<int> array = {1};
    Solution newSol;
    cout << "LAST INDEX: " << newSol.removeElement(array, 1) << endl;
    for(int i: array)   cout << i;


    return 0;
}