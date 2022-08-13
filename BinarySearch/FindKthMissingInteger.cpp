#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int findMissing(vector<int> &array, int k){
        int i=0; int j=array.size()-1;
        int midpoint;

        while(i<=j){
            midpoint = i + (j-i)/2;

            if((array[midpoint]-(midpoint+1)) >= k)   j=midpoint-1;
            else i = midpoint+1;
        }

        if(j<0) return k;   //Missing element is smaller than array[0].
        int base = array[j];    //Before index j: (array[j]-(j+1))  elements are missing which is < k
        int add = k - (array[j]-(j+1)); //After index j increase the value until the kth missing value is reached.

        return (base + add);
    }
};

int main(){
    vector<int> array = {2,3,4,7,11};
    Solution find;
    
    cout << find.findMissing(array, 5);
    return 0;
}