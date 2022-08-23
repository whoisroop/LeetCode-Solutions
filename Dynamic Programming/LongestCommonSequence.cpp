#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//Printing largest common subsequence.
class Solution{
public:
    void f(string &sa, string &sb, int ia, int ib, int la, int lb, string &seq, string &sol){
        if(ia==la || ib==lb){
            if(seq.length()>=sol.length()) sol = seq;
            return;
        }

        // cout << ia << " " << ib << " | ";
        if(sa[ia]==sb[ib]){
            seq += sa[ia];
            f(sa, sb, ia+1, ib+1, la, lb, seq, sol);
            seq.pop_back();
        }
        else{
            f(sa, sb, ia+1, ib, la, lb, seq, sol);
            f(sa, sb, ia, ib+1, la, lb, seq, sol);
        }

        return;
    }

    string findLCS(string sa, string sb){
        int la = sa.size(); int lb = sb.size();
        string seq = "";
        string subseq = "";
        f(sa, sb, 0, 0, la, lb, seq, subseq);

        return subseq;
    }
};

int main(){
    string sa = "adcbc";
    string sb = "dcadb";
    Solution find;
    cout << find.findLCS(sa, sb) << endl;
    vector<int> array = {1,3,4,9,5};
    sort(array.begin(), array.end(), greater<int>());
    for(int i: array) cout << i << " " ;
    return 0;
}