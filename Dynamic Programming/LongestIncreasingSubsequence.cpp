#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int fx(vector<int> &nums){ //Binary Search Overwriting Solution 
        int n = nums.size()-1;
        vector<int> seq;
        int count = 1;
        seq.push_back(nums[0]);

        for(int i=1; i<=n; i++){
            if(nums[i]>seq.back()){
                seq.push_back(nums[i]);
                count++;
            }
            else{
                int index = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                seq[index] = nums[i];
            }
        }

        return count;
    }

    int fy(vector<int> &nums){  //Using Arrays
        int n = nums.size()-1;
        vector<int> size(n+1, 1), hash(n+1, 0);
        for(int i=0; i<=n; i++) hash[i]=i;

        int maxi = 1;
        int li = 0;
        for(int i=1; i<=n; i++){
            for(int pi=0; pi<i; pi++){
                if(nums[i]>nums[pi] && ((size[pi]+1)>size[i])){
                    size[i] = (size[pi]+1);
                    hash[i] = pi;
                    if(size[i]>maxi){
                        maxi = size[i];
                        li = i;
                    }
                }
            }
        }
        
        cout << "Sequence In Reverse: " << endl;
        int i=li;
        while(hash[i]!=i){
            cout << nums[i] << " ";
            i = hash[i];   //Prev Index
        }
        cout << nums[i] << endl;

        return maxi;
    }

};

int main(){
    vector<int> nums = {1,7,8,4,5,6,-1,9};
    Solution newSol;
    cout << newSol.fy(nums);

    return 0;
}