// Quick Sort Algorithm
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int partition(int start, int end, vector<int> &A){
        int p = start - 1;  //Elements in A[0 ... p] are lesser than the pivot.
        int pivot = A[end];

        for(int i=start; i < end; i++){
            if(A[i] < pivot){ p += 1; swap(A[p], A[i]); }
        }

        swap(A[end], A[p + 1]);
        return (p + 1);
    }
public:
    void quicksort(int start, int end, vector<int> &A){
        if(start >= end) return;

        int pindex = partition(start, end, A);
        quicksort(start, pindex - 1, A);
        quicksort(pindex + 1, end, A);

        return;
    }
};

int main(){
    Solution solve;
    vector<int> A = {35,50,15,25,80,20,90,45};
    solve.quicksort(0, A.size() - 1, A);
    for(int i: A) cout << i << " ";
    return 0;
}