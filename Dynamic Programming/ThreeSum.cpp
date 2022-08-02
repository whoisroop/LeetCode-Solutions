#include<bits/stdc++.h>
using namespace std;

//Find distinct triplets where: a+b+c=0
//Apply two pointer approch by assuming a to be constant & for every value of a find (b,c) where, b+c = -(a);

class Solution{
public:
    vector<vector<int>> threeSum(vector<int> &array){
        sort(array.begin(), array.end());
        int li = array.size()-1;
        int low, high;

        vector<vector<int>> solution; 

        for(int ptrA=0; ptrA<=(li-2); ptrA++){    //Traverse A till last third element.
            int sum = 0-array[ptrA];    //A
            low = ptrA+1; high = li;   // B & C respectively
            
            if(ptrA==0 || (array[ptrA]!=array[ptrA-1])){
                while(low<high){
                    if(array[low]+array[high]==sum){
                        vector<int> triplet;
                        triplet.push_back(array[ptrA]);
                        triplet.push_back(array[low]);
                        triplet.push_back(array[high]);
                        solution.push_back(triplet);    //Save Triplet

                        while(low<high && array[low]==array[low+1]) low++;
                        while(low<high && array[high]==array[high-1]) high--;
                        low++; high--;  //Moved to next distinct elements.
                    }

                    else if(low<high && array[low]+array[high]<sum)   low++;
                    else if(low<high && array[low]+array[high]>sum)   high--;
                }
            }

            else continue;
        }

        return solution;
    }

    vector<vector<int>> threeSumHASH(vector<int> array, int target){
        int n = array.size();
        vector<vector<int>> triplets;
        unordered_map<int, int> mpp;    //To map value to frequency.
        for(int &i: array)  mpp[i]++;

        for(int i=0; i<(n-1); i++){
            //DECREASE the frequency of element: Currently A 
            //(Helps in finding if there exists C)
            mpp[array[i]]--;

            for(int j=i+1; j<(n); j++){
                //DECREASE the frequency of element: Currently B
                mpp[array[j]]--;
                int find = (target - (array[i]+array[j]));  //C = Target - (A+B)
                if((mpp.find(find)!=mpp.end()) && (mpp[find]!=0)){
                    vector<int> values;
                    values.push_back(array[i]);
                    values.push_back(array[j]);
                    values.push_back(find);
                    triplets.push_back(values);
                }

                mpp[array[j]]++;    //Reset the frequency.
            }

            mpp[array[i]]++;
        }

        //Remove duplicates:
        for(auto &array: triplets)  sort(array.begin(), array.end());

        set<vector<int>> st(triplets.begin(), triplets.end());
        vector<vector<int>> solution(st.begin(), st.end());

        return solution;
    }
};

int main(){
    vector<int> array = {-1,0,1,2,-1,-4};
    Solution newSol;
    vector<vector<int>> triplets = newSol.threeSumHASH(array, 0);

    for(auto i: triplets){
        for(int j: i)   cout << j << " ";
        cout << endl;
    }

    return 0;
}