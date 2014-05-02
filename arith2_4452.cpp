#include<iostream>
#include<math.h>
#include<string>
#include<stdlib.h>

using namespace std;
typedef long long int ll;


void operate(ll& first, ll& second,char oper)
{
	if(oper == 0)
		first=second;
	else if(oper == '+')
		first=first+second;
	else if(oper == '-')
		first=first-second;
	else if(oper=='*')
		first=first*second;
	else if(oper=='/')
		first=first/second;
	return;
}



ll calculator(string expr)
{
	ll first=0;
	ll second=0;

	char oper=0;
	char curr_expr;
	for(int i=0;i<expr.size();i++)
	{
		curr_expr=expr[i];
		if(curr_expr==32)
			continue;
		
		if(curr_expr>=48 && curr_expr<=57)//if a number
		{
			second=second*ll(10)+ll(expr[i]-'0');
			
		}
		else if(curr_expr>=42 && curr_expr<=47)
		{
				operate(first,second,oper);
				oper=curr_expr;
				second=0;
		}
		else if(curr_expr=='=')
		{
			operate(first,second,oper);
			return first;
		}
	}
	return first;
}	

			

int main()
{
	string test;
	getline(cin,test);//So as not to mix getline and normal cin
	int T=atoi(test.c_str());
	string expr;
	for(int i=0;i<T;i++)
	{
		cin.ignore(256,'\n');
		getline(cin,expr);
		cout<<calculator(expr)<<'\n';
	}
	return 0;
}
