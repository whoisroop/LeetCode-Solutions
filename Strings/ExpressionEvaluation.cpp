// LeetCode - 
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int evaluate(int &X, int &Y, char &operation){
        switch(operation){
            case '+':
                return X + Y;
            case '-':
                return X - Y;
            case '*':
                return X * Y;
            case '/':
                if(Y == 0) return INT32_MAX;
                return X / Y;
        }
        
        return 0;
    }
    
    int precedence(char &symbol){
        if(symbol == '+' || symbol == '-') return -1;
        else if(symbol == '*') return 0;
        else if(symbol == '/') return 1;
    }
    
    int expression(string &A){
        int N = A.size();
        stack<int> value;
        stack<char> operators;   //1: Addition 2: Subtraction 3: Multiplication 4: Division
        
        // If value: Push into the value stack.
        // If operator: Pop all the smaller precedence operators and perform the operation & push the result into value stack.
        for(int i=0; i<N; i++){
            if(A[i] == ' ') continue;
            
            if(A[i] >= '0' && A[i] <= '9'){
                int current = 0;
                while(isdigit(A[i]) && i < N){ 
                    current = current * 10 + (A[i]-'0'); 
                    i += 1;
                }
                
                value.push(current); 
                i -= 1;
            }
            else{
                if(operators.empty() == true || precedence(operators.top()) < precedence(A[i])) operators.push(A[i]);
                
                else{
                    while(operators.empty() != true && precedence(operators.top()) >= precedence(A[i])){
                        int Y = value.top(); value.pop();
                        int X = value.top(); value.pop();

                        value.push(evaluate(X, Y, operators.top())); operators.pop();
                    }
                    
                    // Lower precedence operations are performed:
                    operators.push(A[i]);
                }
            }
        }
        
        while(!operators.empty()){
            int Y = value.top(); value.pop();
            int X = value.top(); value.pop();

            value.push(evaluate(X, Y, operators.top())); operators.pop();
        }
        
        return value.top();
    }
};

int main(){
    Solution solve;
    
    return 0;
}