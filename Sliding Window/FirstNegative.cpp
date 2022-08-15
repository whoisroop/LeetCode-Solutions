//Find the first negative number in every window of size k.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
    vector<int> findFirstNegative(vector<int> &array, int window){
        int i=0; int j=0;
        vector<int> firstNegative;
        queue<int>  q;

        int li = array.size()-1;
        while(j<=li){
            if((j-i+1)<window){
                if(array[j]<0)  q.push(array[j]);
                j++;
            }
            else{
                if(array[j]<0)  q.push(array[j]);
                
                if(q.empty()==true) firstNegative.push_back(0);
                else firstNegative.push_back(q.front()); 

                //Sliding The Window
                if(q.front() == array[i])   q.pop();
                i++; j++;
            }
        } 

        for(const int &i: firstNegative)    cout << i << " ";
        return firstNegative;
    }
};

int main(){
    vector<int> array = {12,-1,-7,8,-15,30,16,28};
    Solution print;
    print.findFirstNegative(array, 3);
    return 0;
}