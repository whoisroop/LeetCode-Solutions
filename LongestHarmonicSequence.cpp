#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int lhs(vector<int> &array){
        //The order will not matter for length of longest harmonic subsequence.
        //MaxElement - MinElement = 1 | Hence the collection will contain 2 distinct elements.
        sort(array.begin(), array.end());
        int n = array.size();

        int i=0, j=1;
        int maxi=0;
        int d;
        while(j<n){
            d = array[j]-array[i];
            cout << "I: " << i << " | J: " << j << " | Difference: " << d;

            if(d==1)    maxi = max(maxi, ((j-i)+1));
            if(d<2){
                j++;
            }
            else{
                i++;
            }

            cout << " | MAX: " << maxi << endl;
        }

        return maxi;

    }
};

int main(){
    vector<int> array = {1,1,1,1};  //1 2 2 2 3 3 5 7
    Solution newSol;
    cout << newSol.lhs(array);
    
    return 0;
}