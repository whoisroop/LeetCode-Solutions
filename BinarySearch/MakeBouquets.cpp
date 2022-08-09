#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    bool isValid(vector<int> &bloom, int maxDays, int bouquets, int nF){
        int n = bloom.size();
        int count=0;

        for(int i=0; i<n-nF; i++){
            bool isMade = false;

            for(int j=0; j<nF; j++){
                cout << "I: " << i << " J: " << j << " | " << bloom[i+j] << " <= " << maxDays << " = " << count << endl; 
                if(bloom[i+j]>maxDays){ i=(i+j); isMade=false; break; } 
                else if(j==(nF-1)){ i=(i+j); isMade=true; }
            }

            if(isMade)  count++;  
        }

        cout << "MIDPOINT: " << maxDays << " BOUQUETS: " << count << endl;
        return (count>=bouquets);
    }
public:
    int minDays(vector<int> &bloom, int bouquets, int nF){  //nF number if flowers needed to make on bouquet.
        if(bloom.size() < bouquets*nF)  return -1;

        int i=0; int j=0;
        for(const int &x: bloom)    j=max(j, x);    //j: Max Days To Bloom
        int midpoint;
        
        while(i<=j){
            midpoint = i + (j-i)/2;

            if(isValid(bloom, midpoint, bouquets, nF)) j = midpoint-1;
            else i = midpoint+1;
        }

        return i;
    }

};

int main(){
    vector<int> bloom = {7,7,7,7,12,7,7};
    int n = 3;  //Number of bouquets
    int nF = 2; //Flowers for each bouquet

    Solution newSol;
    cout << newSol.minDays(bloom, n, nF);

    return 0;
}