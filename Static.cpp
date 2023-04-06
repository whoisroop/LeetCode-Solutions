#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
public:
    static int x;
    int getX(){ cout << x << endl; return x; }
    void setX(int value);
};

int Solution::x = 10;
void Solution::setX(int value) {this->x = value; }

int main(){
    Solution solve;
    solve.getX();
    solve.setX(20);
    solve.getX();
    return 0;
}