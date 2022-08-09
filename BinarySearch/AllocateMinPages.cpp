#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    bool isValid(vector<int> &book, int people, int maxPages){
        //Find how many people are required to distribute all the book such that no one gets more than max pages.
        //If required people <= people (K)  return true else false
        int nP = 1; //Number Of People For The Distribution
        int n = book.size();
        int pages = 0;
        for(int i=0; i<n; i++){
            if(book[i]>maxPages)    return false;
            pages += book[i];

            if(pages>maxPages){
                pages = book[i];
                nP++;
            }
        }

        return (nP<=people);
    }
public:
    int findMin(vector<int> &book, int people){
        if(people>book.size())  return -1;  //Books are less than number of people.

        int sum=0;
        for(const int &i: book) sum+=i;
        int i=0; int j=sum;
        int midpoint;   //Limit Of Max Pages Allotment

        while(i<=j){
            midpoint = i + (j-i)/2;

            if(isValid(book, people, midpoint)) j = midpoint-1;
            else i = midpoint+1;
        }

        return i;
    }
};

int main(){
    vector<int> book = {10,20,30,40};
    Solution workload;
    cout << workload.findMin(book, 3);
    return 0;
}