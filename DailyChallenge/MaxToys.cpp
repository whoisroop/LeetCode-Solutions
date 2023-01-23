#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<int> maximumToys(int n, vector<int> cost, int Q, vector<vector<int>> query){
      vector<int> solution(Q, 0);
      
      for(int q=0; q<Q; q++){
          int amount = query[q][0];
          int broken = query[q][1];
          vector<int> toys = cost;
          
          for(int i=1; i<=broken; i++) toys[query[q][1 + i] - 1] = INT32_MAX;
          
          int count = 0;
          sort(toys.begin(), toys.end());
        //   for(int i=0; i<n; i++) cout << toys[i] << " ";
        //   cout << endl;
          for(int i=0; i < n - broken; i++){
              if(amount - toys[i] >= 0){
                  amount -= toys[i];
                  count += 1;
              }
              else break;
          }

          cout << count << endl;
          
          solution[q] = count;
      }
      
      return solution;
  }
};

int main(){
    Solution find;
    vector<int> cost = {8, 6, 9, 2, 5};
    vector<vector<int>> query = {{12,2,3,4},{30,0}};
    find.maximumToys(5, cost, 2, query);
    return 0;
}