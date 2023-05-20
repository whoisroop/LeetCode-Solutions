// GFG - BIKE RACING.
// Description - Geek is organising a bike race with N bikers. The initial speed of the ith biker is denoted by Hi Km/hr and the acceleration of ith biker as Ai Km/Hr2. A biker whose speed is 'L' or more, is considered be a fast biker. The total speed on the track for every hour is calculated by adding the speed of each fast biker in that hour. When the total speed on the track is 'M' kilometers per hour or more, the safety alarm turns on. 
// Find the minimum number of hours after which the safety alarm will start.

// Example:
// N = 3, M = 400, L = 120
// H = {20, 50, 20}
// A = {20, 70, 90}

// Speeds of all the Bikers at ith hour
// Biker1= [20  40  60  80 100] 
// Biker2= [50 120 190 260 330]
// Biker3= [20 110 200 290 380] 

// Initial Speed on track  = 0
// Speed on track after 1st Hour = 120
// Speed on track after 2nd Hour = 190+200 = 390
// Speed on track after 3rd Hour = 260+290 = 550
// (550 > 400) The buzzer will go off at 3rd hour.

// Approach:
// Speed of each biker at ith hour: S(i) = H[i] + A[i] * i
// Trackspeed = S(1) + S(2) + ... ; Where S(i) >= L
// For above example:
// Biker 1 : 20 + 20 * i
// Biker 2 : 50 + 70 * i
// Biker 3 : 20 + 90 * i
// (20 + 20 * i) >= L ; (50 + 70 * i) >= L ; (20 + 90 * i) >= L
// Trackspeed = (20 + 20 * i) + (50 + 70 * i) + (20 + 90 * i) >= M OR 20 + 50 + 20 + i * (20 + 70 + 90) >= M ; Given the speed of each biker >= L.
// The value increases linearly with i, linear search will cost O(N) the problem can be solved in O(logN) using binary search.
// If at for example 2nd hour the trackspeed is not attained, it cannot be attained on hour lesser than 2 i.e. 0 or 1. The approach or thinking for binary search.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int buzzTime(int N, int M, int L, int H[], int A[]){
        int solution = 0;
        
        int i=0, j=INT32_MAX;
        while(i<=j){
            int midpoint = i + (j-i)/2;
            
            int trackspeed = 0;
            for(int i=0; i<N; i++){
                int speed = H[i] + A[i] * midpoint;
                if(speed >= L) trackspeed += speed;
            }
            
            if(trackspeed >= M){ solution = midpoint; j = midpoint-1; }
            else{ i = midpoint+1; }
        }
        
        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}