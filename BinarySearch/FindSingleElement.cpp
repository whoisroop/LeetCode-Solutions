//Find single element in sorted array where every element appears twice except for one.
//DISTINGUISH BETWEEN LEFT & RIGHT OF THE REUIRED ELEMENT
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    //DISTINGUISH BETWEEN LEFT & RIGHT OF THE REUIRED ELEMENT
    //The idea is to decrease the search space, where the partitioning will be done on the basis of left part & right part of the single element to be found:
    //The left part will contain first occurrence on even index & second one on odd index.
    //However after the index of the single element the order changes.
    //Find the first element after the left part: Single Element (UpperBound Similarity).
    int findSingleElement(vector<int> &array){
        if(array.size()==1) return array[0];
        int i=0; int j=array.size()-1;
        int mid;

        //Check if the mid lies in the left part if not i = mid+1.
        //If index is even check (compare) the next element. 
        //If index is odd check (compare) the previous element. 
        //EvenNumber XOR 1 = Next Odd Number
        //OddNumber XOR 1 = Previous Even Number    
        while(i<=j){
            mid = i + (j-i)/2;

            if(mid%2==0){   //For Even INDEX
                if(array[mid]==array[mid+1])    i=mid+1;
                else j=mid-1;
            }
            else{   //For ODD INDEX
                if(array[mid]==array[mid-1])    i=mid+1;
                else j=mid-1;
            }
        }

        return array[i];
    }

};

int main(){
    vector<int> array = {1,1,2,3,3,4,4,5,5};
    Solution find;
    cout << find.findSingleElement(array);
    return 0;
}