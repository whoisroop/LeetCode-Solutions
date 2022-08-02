//Partition Array For Max Sum: Front Partitioning REFER PALINDROMEPARTITION II
#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    //f(i): Returns the max sum by partitioning array of size N starting from ith index.
    int f(int i, int n, int ml, vector<int> &value, vector<int> &dp){    //ml: maxLength of partition
        if(i>=n) return 0;

        if(dp[i]!=-1) {
            cout << "DP: INDEX: " << i << endl;
            return dp[i];
        }

        int sum = 0;
        int maxi = -1e8;
        int maxElement = -1e8;
        for(int p=i; p < min(i+ml, n); p++){  //((p-i)+1)<=ml && (p<n)
            maxElement = max(maxElement, value[p]);
            //((p-i)+1): Number Of Element In Current Partition
            sum = ((p-i)+1)*maxElement + f((p+1), n, ml, value, dp); 
            cout << "INDEX: " << i << " | PARTITION: " << p << " | MAX ELEMENT: " << maxElement << endl;
            cout << "SUM: " << sum << endl;  
            if(sum>maxi)    maxi = sum;
        }

        return dp[i] = maxi;
    }

public:
    int maxPartitionSum(vector<int> value, int maxPartitionLength){
        int n = value.size();
        vector<int> dp(n, -1);
        return f(0, n, maxPartitionLength, value, dp);
    }

};

int main(){
    vector<int> value = {1,4,1,5,7,3,6,1,9,9,3};    //{1 | 4 1 5 7 | 3 6 1 9 | 9 3}
    int maxPartitonLength = 4;
    Solution newSol;
    cout << newSol.maxPartitionSum(value, maxPartitonLength);

    return 0;
}