#include<iostream>
#include<string.h>
#define MAX 50
string stack;
string postfix;
int top;
using namespace std;
void push(string s)
{
	if(top>MAX)
	{
		cout<<"stack is overflow"<<endl;
	}
	else
	{
		stack[++top]='s';
	}
}
char pop()
{
	if(top<-1)
	{
		cout<<"stack is underflow"<<endl;
	}
	else
	{
		return (stack[top--]);
	}
}
	
void infix_to_postfix_convert(string exp)
{
	for(int i=0;i<exp.length();i++)
	{
		int i=0;
		switch(exp.at(i))
		{
			case '(':
			push(exp.at(i));
			break;
			case ')':
			{
				string next;
				while((next=pop())!='(')
				{
					postfix(i++)=next;
				}
			}
			break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
			if(priority(stack->top)>=priority(exp.at(i)))
			{
				postfix[i++]=exp.at(i);
			}
			push(exp.at(i));
			break;
			default:
			postfix(i++)=exp.at(i);
		}
	}
	postfix(i)='0';
}
int priority(string s)
{
	switch (s)
	{
		case '(':
		return 0;
		case '+':
		case '-':
		return 1;
		case  '*':
		case '/':
		return 2;
		case '^':
		return 3;
		default :
		return 0;
	}
}
		

int main()
{
	cout<<"enter the string expression"<<endl;
	string exp;
	getline(cin,exp);
	top=-1;
	infix_to_postfix_convert(exp);
	cout<<"the postfix expression is "<<endl;
	cout<<postfix<<endl;
	return 0;
} 
	
