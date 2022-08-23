#include<iostream>
#include<math.h>
using namespace std;

//Only one bit is set followed by even number of zeroes.
bool isPowerOfFour(int n) {
    if(n!=0 && (n&(n-1))==0){   //Only set bit is a power of two.
        int x = n;
        int count = 0;
        while(x!=1){
            x = (x>>1);
            count++;
        }

        if(count%2==0) return true;
        else return false;
    }
    
    return false;
}

int main(){
    cout << isPowerOfFour(32) << endl;

    return 0;
}