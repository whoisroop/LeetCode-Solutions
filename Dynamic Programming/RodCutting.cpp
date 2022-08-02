//Different rod lengths have different prices.
//Cut the rod of length N into different pieces to gain max profit.
//Hot To think: Instead of breaking original into parts, try to make an identical rod with length N with different size pieces to equal max amount.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int> &price){
        int n = price.size()-1;
        int length = n+1;
        vector<int> prev(n+2, 0);

        //BaseCase
        for(int capacity=1; capacity<=length; capacity++){
            prev[capacity] = (capacity*price[0]);
        }

        for(int index=1; index<=n; index++){
            for(int capacity=0; capacity<=length; capacity++){
                int notTake = 0 + prev[capacity];
                int take = -1e8;
                if((index+1)<=capacity) take = price[index] + prev[capacity-(index+1)]; 

                prev[capacity] = max(take, notTake);
            }
        }

        return prev[length];
    }

};

int main(){
    vector<int> rod = {2,5,7,8,10};
    Solution newSol;
    cout << newSol.maxProfit(rod);
    return 0;
}