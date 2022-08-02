#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int reverse(int a){
        int b=0;
        int digit = 0;
        int flag = 1;
        if(a<0) flag = -1;
        a = abs(a);
        while(a>0){
            digit = a%10;
            a = a/10;
            if(b > INT32_MAX/10)    return 0;
            b = b*10+digit;
        }

        return (flag*b);
    }
    
};

int main(){
    int x = INT32_MAX-8;
    Solution newSol;
    cout << newSol.reverse(x);

    return 0;
}