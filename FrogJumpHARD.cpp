#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    bool f(int i, int lastJ, int li, vector<int> &stones){
        if(i==li)   return true;
        if(i>li)    return false;

        int j=1;
        int jump=stones[i+j]-stones[i];
        while(jump <= (lastJ+1)){
            if((jump>=(lastJ-1) && (jump<=lastJ+1))){
                cout << "JUMP: " << i << " -> " << jump << endl;
                if(f(i+j, jump, li, stones) == true)    return true;
            }
            j = j+1;
            jump = stones[i+j]-stones[i];
        }

        return false;
    }

public:
    bool isPossible(vector<int> &stones){
        int li = stones.size()-1;
        return f(0, 0, li, stones);
    }
};

int main(){
    vector<int> stones = {0,1,2,3,4,8,9,11};
    Solution newSol;
    cout << newSol.isPossible(stones);

    return 0;
}