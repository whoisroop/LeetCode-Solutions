//LeetCode - 162 Find Peak Element
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    //If taking a random element from array we can determine whether the answer will lie on the left or right half then apply binary search.
    //Finding the peak element: Element greater than its neighbours!
    //If the midpoint element is not the answer then the element which is greater is the part where (atleast one solution) the answer lies.
    //Example: 1(I) 2 1 3(M) 5 6 7(J)
    //The left neighbour of 3 is smaller where as the right neighbour is greater:
    //The right neighbour is greater means the current element will be one of its neighbour which is smaller.
    //If we encounter another element on right smaller than that of the element 5, then 5 will be the answer.
    //If we do not encounter smaller, instead greater then 5 will be its left smaller & if the right of the element 6 is smaller then 6 will be answer.
    //If we do not encounter any smaller elements: we'll reach the last (or first) element & as that is the element already having a smaller element from previous (6) it'll be answer. The value in this case kept increasing & as a result the end element was the answer.  
    int findPeak(vector<int> &array){
        int i=0; int j=array.size()-1;
        int midpoint;

        int li = array.size()-1;
        if(li==0)   return 0;   //If single element is present in the array.
        while(i<=j){
            midpoint = i + (j-i)/2;

            if(midpoint>0 && midpoint<li){
                if(array[midpoint-1] < array[midpoint] && array[midpoint] > array[midpoint+1])  return midpoint;
                else if(array[midpoint-1]>array[midpoint+1]) j=midpoint-1;
                else i=midpoint+1;
            }

            else if(midpoint==0){
                if(array[midpoint]>array[midpoint+1])   return midpoint;
                else i=midpoint+1;
            }

            else{
                if(array[midpoint]>array[midpoint-1])   return midpoint;
                else j=midpoint-1;
            }
        }

        return -1;
    }
};

int main(){
    vector<int> array = {1,2,1,3,5,6,7};
    Solution find;
    int index = find.findPeak(array);
    cout << array[index];
    return 0;
}