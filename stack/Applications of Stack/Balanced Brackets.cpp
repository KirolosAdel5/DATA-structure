/* #include<bits/stdc++.h>
using namespace std;
bool areBracketsBalanced(string expr) 
{   
    stack<char> s; 
    char x; 
    for (int i = 0; i < expr.length(); i++)  
    { 
        if (expr[i] == '(' || expr[i] == '['|| expr[i] == '{')  
        { 
            s.push(expr[i]); 
            continue; 
        } 

        s.empty()? false: true; 
  
        switch (expr[i]) { 
        case ')':   
            x = s.top();
            s.pop(); 
            if (x == '{' || x == '[') 
                return false; 
            break; 
  
        case '}': 
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '[') 
                return false; 
            break; 
  
        case ']': 
  
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '{') 
                return false; 
            break; 
        } 
    } 
  
    return (s.empty()); 
} 
int main(){
    string expr;cin>>expr;
    areBracketsBalanced(expr)?cout << "Balanced":cout << "Not Balanced"; 
    return 0;
} */

#include <iostream>
#include <string>
using namespace std;
struct Stack {
    int arr[100];
    int top = -1;
    void push(int val) {
        if (top == 99) return;
        arr[++top] = val;
    }
    void pop() {
        if (isEmpty()) return;
        top--;
    }
    int top_val() {
        if (isEmpty()) return -1;
        return arr[top];
    }
    bool isEmpty() {
        if (top == -1) return true;
        else return false;
    }

};

bool Pair(char open, char close) {
    if (open == '(' && close == ')') return true;
    else if (open == '{' && close == '}') return true;
    else if (open == '[' && close == ']') return true;
    return false;
}

bool Balanced(string exp) {
    Stack open_brackets;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            open_brackets.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (open_brackets.isEmpty()) return false;
            else if (Pair(open_brackets.top_val(), exp[i]) == false) return false;
            open_brackets.pop();
        }
    }
    if (open_brackets.isEmpty()) return true;
    else return false;
}

int main() {
    string s;
    cin >> s;
    if (Balanced(s)) cout << "Expression is balancedn";
    else cout << "Expression is not balancedn";

    return 0;
}
