#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void f(vector<int> &array, int k, string &sequence){
        int n = array.size();

        //Base Case. 
        //When we have to find the 0th sequence it'll contain rest of the array in same order.
        if(k==0){ 
            for(int i:array)    sequence += to_string(i);
            return;
        }
        
        int groupSize = 1; //(n-1)!
        for(int i=1; i<n; i++)  groupSize *= i;
        
        int index = (k/groupSize);  //Find which group & Find the starting element.
        sequence += to_string(array[index]);
        array.erase(array.begin() + index); //Remove the element which is the group starter.
        
        f(array, (k%groupSize), sequence);
        return;
    }
    

    string getPermutation(int n, int k){
        //k-1   : 0th Based Indexing Is Followed
        string solution;
        vector<int> array(n, 0);
        for(int i=0; i<n; i++)  array[i] = (i+1);
        
        f(array, (k-1), solution);

        cout << solution << endl;

        return solution;
    }
};

int main(){
    Solution newSol;
    // 1<=n<=9
    newSol.getPermutation(4, 9);
    return 0;
}