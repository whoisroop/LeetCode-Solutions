#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Solution{
public:
    vector<int> findMax(vector<int> &array, int window){
        int i=0; int j=0;
        //Use deque<int> for faster execution: Same function as vector/list & faster access to elements.
        list<int> l;    
        vector<int> maxi;

        int li = array.size()-1;
        while(j<=li){
            if((j-i+1)<window){
                if(l.empty()==true) l.push_back(array[j]);
                else{
                    //If in the given window we have another greater element on right, discard the previous elements & start storing from that element onwards.
                    while(l.empty()!=true && l.back()<array[j]) l.pop_back();
                    l.push_back(array[j]);
                }

                j++;
            }
            else{
                if(l.empty()==true) l.push_back(array[j]);
                else{
                    while(l.empty()!=true && l.back()<array[j]) l.pop_back();
                    l.push_back(array[j]);
                }

                maxi.push_back(l.front());
                
                //Reset the first element for next window
                if(l.front()==array[i]) l.pop_front();
                i++; j++;
            }
        }

        for(int i: maxi)    cout << i << " ";
        return maxi;
    }
};

int main(){
    vector<int> array = {1,3,1,2,0,5};
    Solution find;
    find.findMax(array, 3);
    
    return 0;
}