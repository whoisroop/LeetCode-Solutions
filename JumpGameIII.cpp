#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool f(int i, vector<int> &visited, int li, vector<int> &array){
        if(array[i]==0) return true;

        if(i+array[i]<=li && visited[i+array[i]] != -1){
            visited[i] = -1;
            cout << "+ Jump From: " << i << " + " << array[i] << " -> " << i+array[i];
            cout << " | Jump To : " << array[i+array[i]] << endl;
            if(f(i+array[i], visited, li, array) == true)    return true;
            visited[i] = 0;
        }
        if(i-array[i]>=0 && visited[i-array[i]] != -1){
            visited[i] = -1;
            cout << "- Jump From: " << i << " - " << array[i] << " -> " << i-array[i];
            cout << " | Jump To : " << array[i-array[i]] << endl;
            if(f(i-array[i], visited, li, array) == true)    return true;
            visited[i] = 0;
        } 

        return false;
    }

    bool canReach(vector<int> &array, int start){
        int li = array.size()-1;
        vector<int> visited(li+1, 0);
        return f(start, visited, li, array);
    }

};

int main(){
    vector<int> array = {4,2,3,0,3,1,2};
    int start = 5;
    Solution newSol;
    cout << newSol.canReach(array, start);

    return 0;
}