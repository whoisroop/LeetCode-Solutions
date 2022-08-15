//Leet Code - 643. Find the subarray of size k with maximum average.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    double findMax(vector<int> &array, int k){
        double window = k;
        int i=0; int j=0;
        double avg=0; double maxi=INT32_MIN;

        int li = array.size()-1;
        while(j<=li){
            if((j-i+1)<window){
                avg += (array[j]/window);
                j++;
            }
            else{
                avg = avg + (array[j]/window);
                maxi = max(maxi, avg);

                avg = avg - (array[i]/window);
                i++; j++;
            }
        }

        return maxi;
    }
};

int main(){
    vector<int> array = {1,12,-5,-6,50,3};
    Solution find;
    cout << find.findMax(array, 4);
    return 0;
}