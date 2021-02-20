#include <bits/stdc++.h>
using namespace std;

int precedence(char op){
	if(op == '+'||op == '-')
	return 1;
	if(op == '*'||op == '/')
	return 2;
	return 0;
}

int applyOp(int a, int b, char op){
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}

int evaluate(string tokens){
	int i;
	stack <int> values;
	stack <char> ops;
	for(i = 0; i < tokens.length(); i++){

		if(tokens[i] == ' ')
			continue;
		
		else if(tokens[i] == '('){
			ops.push(tokens[i]);
		}
		
		else if(isdigit(tokens[i])){
			int val = 0;
			
			// There may be more than one
			// digits in number.
			while(i < tokens.length() && isdigit(tokens[i]))
			{
				val = (val*10) + (tokens[i]-'0');
				i++;
			}
			values.push(val);
			i--;
		}
	
		else if(tokens[i] == ')')
		{
			while(!ops.empty() && ops.top() != '(')
			{
				int val2 = values.top();
				values.pop();
				
				int val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			if(!ops.empty())
			ops.pop();
		}
		else
		{
			while(!ops.empty() && precedence(ops.top())
								>= precedence(tokens[i])){
				int val2 = values.top();
				values.pop();
				
				int val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			ops.push(tokens[i]);
		}
	}

	while(!ops.empty()){
		int val2 = values.top();
		values.pop();
				
		int val1 = values.top();
		values.pop();
				
		char op = ops.top();
		ops.pop();
				
		values.push(applyOp(val1, val2, op));
	}
	return values.top();
}

// C++ Program to convert prefix to Infix
#include <iostream>
#include <stack>
using namespace std;
 
// function to check if character is operator or not
bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  }
  return false;
}
 
string preToInfix(string pre_exp) {
  stack<string> s;
 
  // length of expression
  int length = pre_exp.size();
 
  // reading from right to left
  for (int i = length - 1; i >= 0; i--) {
 
    // check if symbol is operator
    if (isOperator(pre_exp[i])) {
 
      // pop two operands from stack
      string op1 = s.top();   s.pop();
      string op2 = s.top();   s.pop();
 
      // concat the operands and operator
      string temp = "(" + op1 + pre_exp[i] + op2 + ")";
 
      // Push string temp back to stack
      s.push(temp);
    }
 
    // if symbol is an operand
    else {
 
      // push the operand to the stack
      s.push(string(1, pre_exp[i]));
    }
  }
 
  // Stack now contains the Infix expression
  return s.top();
}
 
// Driver Code
int main() {
  string pre_exp = "*-A/BC-/AKL";
  cout << "Infix : " << preToInfix(pre_exp);
  return 0;
}
int main() {
	cout << evaluate("10 + 2 * 6") << "\n";
	cout << evaluate("100 * 2 + 12") << "\n";
	cout << evaluate("100 * ( 2 + 12 )") << "\n";
	cout << evaluate(preToInfix("*-/2356"));

	return 0;
}

// This code is contributed by Nikhil jindal.
