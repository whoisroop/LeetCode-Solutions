// GFG - Find Nth Root Of Value.

#include<iostream>
using namespace std;

class Solution{
	public:
	double power(int value, int n){
	    if(n == 0) return 1;
	    
	    double p = power(value, n/2);
	    
	    if(n%2==0) return p*p;
	    else return p*p*value;
	}
	
	int NthRoot(int n, int value)
	{
	    int minvalue = 0, maxvalue = value;
	    int midpoint;
	    
	    while(minvalue <= maxvalue){
	        midpoint = (minvalue + (maxvalue-minvalue)/2);
	        
	        double observed = power(midpoint, n);
	        
	       // cout << minvalue << " - " << maxvalue << " = " << midpoint << " || " << observed << endl;
	        if(observed == value) return midpoint;
	        
	        if(observed > value) maxvalue = midpoint-1;
	        else minvalue = midpoint+1;
	    }
	    
	    return -1;
	}  
};