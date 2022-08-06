#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    double power(double x, int n){ //x*x*x*... n times
        if(n==0)    return 1;

        double t = power(x, n/2);
        if(n%2==0)  return t*t;
        else    return x*t*t;
    }

    double findRoot(int value, int x){
        //Find (value)^(1/x)
        //The answer will lie in the range [1 2 3 ... value]    Max: (value)^(1/1)
        double i = 1; double j = value;   //Find the value using binary search such that a*a*a*...x times = value
        double mid = 0;
        double precision = 1e-6;
        while((j-i)>precision){  //Accurate upto 5 decimal points.
            mid = (i+j)/2;

            if(power(mid, x)<value)  i=mid;
            else  j=mid;
        }

        cout << mid << endl;
        return mid;
    }

};

int main(){
    Solution newSol;
    newSol.findRoot(15,4);
    return 0;
}