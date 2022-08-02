#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& array, int target) {
        sort(array.begin(), array.end());
        int solution;
        int n = array.size();
        
        int mini=1e8;
        for(int iA=0; iA<=(n-3); iA++){
            int sum=0;
            int i=iA+1, j=n-1;

            while(i<j){
                // cout << array[iA] << " + " << array[i] << " + " << array[j] << endl;
                sum = array[iA]+array[i]+array[j];

                if(abs((target-sum))<mini){
                    solution = sum;
                    mini = abs(target-sum);
                }
                
                if(target>sum) i++;
                else    j--;
            }
        }
        
        return solution;
    }
};

int main(){
    vector<int> array = {1,1,1,0};
    Solution newSol;
    cout << newSol.threeSumClosest(array, -100);
}