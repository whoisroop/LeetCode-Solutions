//Find the maximum sum of subarray of size k.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int findMaxSum(vector<int> &array, int window){
        int i=0; int j=0;
        int sum=0; int maxi=INT32_MIN;

        int li = array.size()-1;
        //Window : (j-i+1)
        while(j<=li){
            if((j-i+1)<window){ 
                sum += array[j];    //Traverse the elements from - First Element ... Last Second Element Of Window
                j++; 
            }
            else{   //(j-i+1)==window
                sum = sum + array[j];   //The window is formed.
                maxi = max(maxi, sum);

                sum = sum - array[i];   //Remove the first element for the next window.
                i++;    j++;
            } 
        }

        return maxi;
    }
};

int main(){
    vector<int> array = {2,7,9,12,3,6,4};
    Solution find;
    cout << find.findMaxSum(array, 3);
    return 0;
}