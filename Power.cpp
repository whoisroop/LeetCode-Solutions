double powP(double x, int n) {  //Positive N
        if(n==0)    return 1;
        double t = powP(x, n/2); //Calculate For | (x)^(n/2) | * (x)^(n/2)
        
        if(n%2 == 0)    return t*t;
        else    return x*t*t;
    }