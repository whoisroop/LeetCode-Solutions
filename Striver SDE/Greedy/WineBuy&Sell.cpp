// GFG: Wine Buy & Sell
// Description: https://practice.geeksforgeeks.org/problems/wine-buying-and-selling/0
// Approach: 
// KEY POINT: Total Buy + Sell = 0.
// Every house with requirement has to buy from other houses.
// As the houses are traversed from left to right, the houses on the right will cost more to buy from the houses on the leftmost side as compared to the current house with requirement.

// Declare & store the selling houses indexes in a queue, LEFT to RIGHT.
// When a house needs to buy, buy from the leftmost or the top of the queue.
// As for the upcoming houses, other elements not the current leftmost will be used to satisfy the needs.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
long long int wineSelling(vector<int> &given, int N){
    vector<int> A = given;
    queue<int> sellout;
    
    long long int total = 0;
    // Store all the selling indexes.
    for(int i=0; i<N; i++) if(A[i] <= 0) sellout.push(i);
    
    // For buy houses: Start buying from the leftmost selling house.
    // As the houses are traversed from left to right & the upcoming houses to the right will cost more to fulfill the demands of the houses (to buy from the left), start buying from the left most houses. AS TOTAL BUY + SELL = 0.
    for(int i=0; i<N; i++){
        if(A[i] <= 0) continue;
        
        // If the sellout <= requirement: POP OUT
        // If the sellout > requirement: DO NOT POP OUT ; Update the sellout quantity.
        int requirement = A[i];
        while(requirement > 0 && sellout.empty() != true){
          int index = sellout.front();
          int sell = abs(A[index]);
          
          if(sell <= requirement){
            total += 1LL * abs(i - index) * sell;
            requirement -= sell; 
            sellout.pop();
          }
          else{ 
              total += 1LL * abs(i - index) * requirement;
              A[index] += requirement; requirement = 0; 
          }
        }
    }
      
    return total;
  }
};

int main(){
    Solution solve;
    
    return 0;
}