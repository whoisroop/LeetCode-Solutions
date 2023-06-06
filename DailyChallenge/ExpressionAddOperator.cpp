// GFG - Expression Add Operators. 
// Description - Given a string S that contains only digits (0-9) and an integer target, return all possible strings to insert the binary operator ' + ', ' - ', or ' * ' between the digits of S so that the resultant expression evaluates to the target value.

// Note:
// Operands in the returned expressions should not contain leading zeros. For example, 2 + 03 is not allowed whereas 20 + 3 is fine. It is allowed to not insert any of the operators.
// If no solution is found, return an empty string array.

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
            
            if(A[i] == '0' && i < N-1 && isdigit(A[i+1])) return INT32_MAX;
            
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
    
    void makeValue(int index, int &target, string current, string &A, vector<string> &solution){
        int N = A.size();
        if(index >= N){
            if(expression(current) == target) solution.push_back(current);
            return;
        }
    
        //Operate: ADD SUBTRACT MULTIPLY
        if(index < N-1){
            makeValue(index+1, target, current + A[index] + '+', A, solution);
            makeValue(index+1, target, current + A[index] + '-' , A, solution);
            makeValue(index+1, target, current + A[index] + '*' , A, solution);
        }
        
        //NotADD:  
        makeValue(index+1, target, current + A[index], A, solution);
        
        return;
    }
    
    vector<string> addOperators(string A, int target) {
        vector<string> solution;
        makeValue(0, target, "", A, solution);
        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}