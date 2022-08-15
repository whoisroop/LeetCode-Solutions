#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
    vector<int> findMax(vector<int> &array, int window){
        int i=0; int j=0;
        queue<int> q;
        vector<int> maxi;

        int li = array.size()-1;
        while(j<=li){
            if((j-i+1)<window){
                if(q.empty()==true) q.push(array[j]);
                else{
                    //If in the given window we have another greater element on right, discard the previous elements & start storing from that element onwards.
                    if(q.front()<array[j]){ 
                        while(q.empty()!=true) q.pop();
                        q.push(array[j]);
                    }
                    else q.push(array[j]);
                }

                j++;
            }
            else{
                if(q.empty()==true) q.push(array[j]);
                else{
                    if(q.front()<array[j]){ 
                        while(q.empty()!=true) q.pop();
                        q.push(array[j]);
                    }
                    else q.push(array[j]);
                }

                maxi.push_back(q.front());
                
                //Reset the first element for next window
                if(q.front()==array[i]) q.pop();
                i++; j++;
            }
        }

        for(int i: maxi)    cout << i << " ";
        return maxi;
    }
};

int main(){
    vector<int> array = {1,3,-1,-3,5,3,6,7};
    Solution find;
    find.findMax(array, 3);
    
    return 0;
}