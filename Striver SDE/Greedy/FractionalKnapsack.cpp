// GFG - Fractional KnapSack.
// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item. 

// Select the one with max value per unit weight.

#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool comparator(Item &A, Item &B){
    return (((1.0*A.value)/A.weight) > ((1.0*B.value)/B.weight));
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item I[], int n)
    {
        sort(I, I + n, comparator);
        double total = 0;
        
        for(int i=0; i<n; i++){
            int value = I[i].value;
            int weight = I[i].weight;
            
            if(W >= weight){ total += value; W -= weight; }
            else{
                total += ((value*1.0)/weight)*W;
                W = 0; break;
            }
        }
        
        return total;
    }
        
};