//LeetCode - 713. Subarray Product Less Than K.
//Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
#include<iostream>
#include<vector>
using namespace std;

//Explanation: Read Docx File
//Number Of Contigious Subarrays Of Array Of Size N: (n*(n+1))/2


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& array, int value) {
        if(value<=1) return 0;
        int i=0; int j=0;
        long int p=1;
        int subarrays=0;
        
        int n = array.size();
        while(j<n){
            p = p*array[j];
            
            if(p<value){
                subarrays += (j-i+1);
                j++;
            }
            else{
                while(p>=value){
                    p = p/array[i]; i++;
                }
                subarrays += (j-i+1);
                j++;
            }
        }
        
        return subarrays;
    }
};

int main(){
    vector<int> array = {};
    return 0;
}