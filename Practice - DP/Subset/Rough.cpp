#include<bits/stdc++.h>
using namespace std;

int main(){
    bitset<16> x;
    x.set(1);
    x.set(3);
    x.set(11);
    cout << x << endl;
    bitset<16> y;
    y.set(1);
    y.set(2);
    y.set(15);
    cout << y << endl;
    cout << (x^y);
    return 0;
}