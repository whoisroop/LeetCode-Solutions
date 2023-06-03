#include<iostream>
#include<vector>
using namespace std;

class Solution{   
public:
    int upperbound(vector<int> &A, int value){
        int i=0, j=A.size()-1;
        int index = 0;
        while(i<=j){
            int midpoint = (i + (j-i)/2);
            
            if(A[midpoint] <= value){ i = midpoint + 1; }
            else j = midpoint - 1;
        }
        
        return i;
    }
    
    // Count Values Less Than:
    int countV(vector<vector<int>> &A, int value){
        int N = A.size();
        int counter = 0;
        for(int i=0; i<N; i++) counter += upperbound(A[i], value);
        
        return counter;
    }
    
    int median(vector<vector<int>> &A, int R, int C){
        // MEDIAN: Generate a search space
        // Pick a value: Values On LEFT == Values On RIGHT == ((TOTAL-1)/2)
        // To tackle duplicate value: 1 1 2 (3) 3 3 4
        // Value On Left = (7-1)/2 = 3
        // Values <= 3 : 6 (Maybe)
        // Values <= 2 : 3 (Not Possible)
        // Move Right: MEDIAN 3.
        int LEFT = (R*C - 1)/2;
        
        int i=1, j = 2001;
        while(i<=j){
            int midpoint = (i + (j-i)/2);
            
            int count = countV(A, midpoint);
            if(count <= LEFT) i = midpoint + 1;
            else j = midpoint - 1;
        }
        
        return i;
    }
};

class Solution{
public:
    //Find the median of the matrix (Of all the numbers present), where each row is sorted.
    //Simply apply a binary search on a search space of [0 ... MaxMedianValue]
    //Where binary search is applied on the number of elements (<= mid) in the matrix.
    //If the number of elements in the matrix (<= mid) is just greater (upper bound) than the (totalNumbers/2), the mid will be answer.
    // 2 3 4 6 6 8 11   The number of elements less than equal to (<=) 6 is 5 where 5 > (6/2) (Number Of Elements Required On Left & Right Of The Element So That The Number Will Be A Median.)

    int upperBound(vector<int> &array, int value){
        int i=0; int j=array.size()-1;
        int mid;

        while(i<=j){
            mid = i + (j-i)/2;
            if(array[mid]<=value)   i = mid+1;
            else    j = mid-1;
        }

        return i;
    }

    //Find Number Of Elements In Array Lesser Than Or Equal To Value
    int findElementsLE(vector<vector<int>> &array, int value){
        //Find Upper Bound Of Value In Given Row By Row & ADD
        int n = array.size();
        int total=0;
        for(int i=0; i<n; i++){
            total += upperBound(array[i], value);
        }

        return total;
    }

    int findMedian(vector<vector<int>> &array){
        int n = array.size();
        int m = array[0].size();
        int value = (1LL*n*m)/2;
        
        int i=0; int j=1e6;
        int mid;

        while(i<=j){
            mid = i + (j-i)/2;

            if(findElementsLE(array, mid) <= value) i=mid+1;
            else j=mid-1;    
        }

        return i;
    }
};

int main(){
    vector<vector<int>> array = {
        {1,3,5},
        {2,6,9},
        {3,6,9}
    };
    Solution newSol;
    cout << newSol.findMedian(array);
    return 0;
};