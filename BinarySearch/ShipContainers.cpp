//LeetCode - 1011
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool isValid(vector<int> &item, int limit, int days){
        int n = item.size();
        int count=1;
        int weight=0;
        for(int i=0; i<n; i++){
            if(item[i]>limit)   return false;
            weight+=item[i];
            if(weight>limit){
                count++;
                weight=item[i];
            }
        }
        // cout << "ISVALID: LIMIT - " << limit << " DAYS - " << count << endl;
        return (count<=days);
    }
    //Find the limit of ship so that the containers are shipped in contigious order within given days.
    int findCapacity(vector<int> &item, int days){  //item[i]: Weight of ith item.
        int i=0; int j=0;
        for(const int &x: item) j+=x;
        int midpoint;   //Limit Of Ship

        while(i<=j){
            midpoint = i + (j-i)/2;
            // cout << "I: " << i << " J: " << j << " | " << midpoint << endl;
            if(isValid(item, midpoint, days))   j=midpoint-1;
            else i=midpoint+1;
        }

        return i;
    }
};

int main(){
    vector<int> item = {3,2,2,4,1,4};
    Solution find;
    cout << find.findCapacity(item, 3);
    return 0;
}