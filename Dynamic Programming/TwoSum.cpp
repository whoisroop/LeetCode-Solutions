#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
    //Find index of two elements a,b where a+b = target. 
    //Make 'a' constant by iterating through every possible 'a': i.e. every element in the array.
    //Using hashmap to find for every a (constant) if there exists b = (target-a).
    vector<int> twoSum(vector<int> &array, int target){
        int n = array.size();
        unordered_map<int, int> mpp;
        vector<int> pair;
        
        for(int i=0; i<n; i++){
            int findElement = (target - array[i]);
            if(mpp.find(findElement) != mpp.end()){
                //If the element exist: The pair is found.
                int indexA = i;
                int indexB = mpp[findElement];
                pair.push_back(indexA);
                pair.push_back(indexB);
                break;  //To Find Single Solution.
            }
            else    mpp[array[i]]=i;    //Else insert the element & index into the map.
        }

        return pair;
    }

};

int main(){
    vector<int> array = {0,1,2,3,5,7,8};
    Solution newSol;
    vector<int> index = newSol.twoSum(array, 8);
    for(int i: index)   cout << array[i] << " ";
    return 0;
}