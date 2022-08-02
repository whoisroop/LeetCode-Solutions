#include<iostream>
#include<vector>
using namespace std;

class QuickSort{
public:
    void quickSort(int l, int r, vector<int> &array){
        //l - Starting Index, r - Ending Index
        if(l>=r)     return;

        //QuickSort Algorithm
        int pivot = array[r];
        int i = (l-1);   //To count & replace the elements smaller than pivot.
        for(int x=l; x<r; x++){ //Last element is the pivot so excluded.
            if(array[x]<pivot){
                //Make space before pivot starting from l and swap.
                i++;
                int temp = array[i];
                array[i] = array[x];
                array[x] = temp;
            }
        }   

        //The i+1 is the position for the pivot as all the elements till i is smaller than pivot.
        i++;
        int temp = array[i];
        array[i] = array[r];    //array[r] -> pivot
        array[r] = temp;
        
        int pivotIndex = i;
        //Now two partitions: l to pivot & pivot + 1 to r

        quickSort(l, pivotIndex-1, array);
        quickSort(pivotIndex+1, r, array);

        return;
    }

};

int main(){
    vector<int> array = {6,3,5,9,2,8};
    QuickSort newSol;
    newSol.quickSort(0, array.size()-1, array);

    for(int x: array){
        cout << x << " ";
    }


    return 0;
}