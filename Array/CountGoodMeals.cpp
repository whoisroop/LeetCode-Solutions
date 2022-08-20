// LeetCode 1711
//A good meal is a meal that contains exactly two different food items with a sum of deliciousness equal to a power of two.
// You can pick any two different foods to make a good meal.
// Given an array of integers deliciousness where deliciousness[i] is the deliciousness of the i​​​​​​th​​​​​​​​ item of food, return the number of different good meals you can make from this list modulo 109 + 7.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//Explanation:
// 1. Method using the two pointer concept & hashmap.
// 2. Traverse through array & store the element in hashmap with its frequency.
// 3. For each element that is added to the hashmap check if there's any element already present in the hashmap such that their sum is a power of 2.
// 4. The maximum valued element possible in array is 2^20 (constraints) now as we're taking sum of two elements the maximum value of sum will be: 2^20 + 2^20 = 2^21.
// 5. Hence, traverse through map to search all the possible elements to make the sum a power of two :
// 6. (2^0 - array[i]) or (2^1 - array[i]) or (2^2 - array[i]) ... (2^21 - array[i]) - For an element array[i] search for possible values in the hashmap. ( array[i] + (2^m - array[i]) = 2^m )
// 7. If the element is present in the map, increase the count by the frequency of the element in hashmap.
// 8. Time Complexity: O(N*22)

class Solution {
public:
    int mod = (7+1e9);
    int countPairs(vector<int>& array) {
        int n=array.size();
        unordered_map<int, int> mpp;
        long int count=0;
        
        for(int i=0; i<n; i++){
            mpp[array[i]]++;
            
            //For every element try & find the element if present such that the sum will be power of two.
            //Constraints: max value = 2^20 & taking sum of two elements of max value: 2*2^20
            //Check if there's present (2^0 - array[i]) or (2^1 - array[i]) or ... (2^21 - array[i])
            for(int x=0; x<=21; x++){
                mpp[array[i]]--;    //Do not count the current element again. Example: 2+2
                if(mpp.find((1<<x) - array[i])!=mpp.end()) count += mpp[((1<<x) - array[i])];
                mpp[array[i]]++;    //Reset.
            }
        }
        
        return (count%mod);
    }
};