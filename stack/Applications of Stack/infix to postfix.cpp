#include <iostream>
#include <stack>
#include <string>
using namespace std;

int Priority(char c){
	if (c == '-' || c == '+')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '^')
		return 3;
	else
		return 0;
}
string infix_to_postfix(string exp){
	stack<char>sta;
	string output="";
	//----------------------
	for(int i=0;i < exp.length();i++){
		if (exp[i]==' ')continue;
		else if(isdigit(exp[i])||isalpha(exp[i])) output+=exp[i];
		else if(exp[i]=='(')sta.push(exp[i]);
		else if(exp[i]==')'){
			while (sta.top()!='(')
			{
				output+=sta.top();
				sta.pop();
			}
			sta.pop();
		}
		else{
			while (!sta.empty()&&Priority(exp[i])<=Priority(sta.top()))
			{
				output+=sta.top();
				sta.pop();
			}
			sta.push(exp[i]);
		}
	}
	while (!sta.empty())
	{
		output+=sta.top();
		sta.pop();
	}
	return output;
}
int main()
{
	string infixExpression = ("(1+3)+7/2*((7+3)*2)");
	cout << infix_to_postfix(infixExpression) << endl;
	return 0;
}