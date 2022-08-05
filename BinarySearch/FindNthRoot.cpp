#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    double findRoot(int value, int x){
        //Find (value)^(1/x)
        //The answer will lie in the range [1 2 3 ... value]    Max: (value)^(1/1)
        double i = 1; double j = value;   //Find the value using binary search such that a*a*a*...x times = value
        double mid = 0;
        while((j-i)>1e-6){  //Accurate upto 5 decimal points.
            mid = (i+j)/2;

            if(mid*mid*mid<value)  i=mid;
            else  j=mid;
        }

        cout << mid << endl;
        return mid;
    }

};

int main(){
    Solution newSol;
    newSol.findRoot(26,3);
    return 0;
}