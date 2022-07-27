#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int f(int index, int capacity, vector<vector<int>> item){
        int boxes = 0;    int units = 1;
        if(index==0){
            if(capacity==0) return 0;
            int x = min(capacity, item[0][boxes]);
            return (x*item[index][units]);
        }
        
        int notTake = 0 + f(index-1, capacity, item);
        int take = -1e8;
        if(item[index][boxes]>0 && capacity>0){
            item[index][boxes] -= 1;
            take = item[index][units] + f(index, capacity-1, item);
        }
        
        return (max(take, notTake));
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size()-1;
        int maxBoxes = -1;
        return f(n, truckSize, boxTypes);
    }
};

int main(){
    vector<vector<int>> items = {{2,1},{4,4},{3,1},{4,1},{2,4},{3,4},{1,3},{4,3},{5,3},{5,3}};
    int max = 13;
    Solution newSol;
    cout << newSol.maximumUnits(items, max);
    return 0;
}