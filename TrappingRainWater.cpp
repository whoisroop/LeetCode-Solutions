#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
private:
    vector<int> prefixMax(vector<int> &array){
        int n = array.size();
        vector<int> prefix(n, 0);
        
        int maxi = array[0];
        for(int i=0; i<n; i++){
            maxi = max(maxi, array[i]);
            prefix[i] = maxi;
        }

        return prefix;
    }

    vector<int> suffixMax(vector<int> &array){
        int n = array.size();
        vector<int> suffix(n, 0);
        
        int maxi = array[n-1];
        for(int i=(n-1); i>=0; i--){
            maxi = max(maxi, array[i]);
            suffix[i] = maxi;
        }

        return suffix;
    }

public:
    int trapRainWater(vector<int> height){
        int n = height.size();

        cout << "WATER HEIGHT: " << endl;
        for(int i: height) cout << i << " ";
        cout << endl;

        vector<int> prefixMx = prefixMax(height);
        vector<int> suffixMx = suffixMax(height);
        
        cout << "Max Prefix: " << endl;
        for(int i: prefixMx) cout << i << " ";
        cout << endl;
        
        cout << "Max Suffix: " << endl;
        for(int i: suffixMx) cout << i << " ";
        cout << endl;

        int water=0;
        for(int i=0; i<n; i++){
            if(prefixMx[i]!=-1 && suffixMx[i]!=-1){
                int mini = min(prefixMx[i], suffixMx[i]);
                water += (mini - height[i]);    //Units of water per index i.
                cout << "Water: " << water << " ";
            }
        }

        cout << endl;

        return water;
    }
};

int main(){
    vector<int> array = {4,2,0,3,2,5};
    Solution newSol;

    cout << endl;

    cout << newSol.trapRainWater(array);

    return 0;
}