#include<iostream>
#include<math.h>
using namespace std;

bool isPowerOfFour(int n) {
    if(n==1)    return true;
    if(n<4)     return false;
    
    if((n&(n-1)) == 0){
        cout << "A" << endl;
        int m = sqrt(n);
        cout << "N - " << n << " & M - " << m << endl;
        if((m&(m-1)) == 0){
            return true;
        }
        else{
            return false;
        }
    }
    
    return false;
}

int main(){
    cout << isPowerOfFour(8) << endl;

    return 0;
}