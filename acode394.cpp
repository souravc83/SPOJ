#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>

using namespace std;

typedef long long ll;

ll codenum(vector<int> A)
{
	int N=A.size();
	vector<ll> B(N,0);

	B[0]=1;
	if(N==1)
		return 1;
		
	if((10*A[0]+A[1])<=26 && A[1]!=0)
		B[1]=2;
	else
	{
		if(N==2 && A[1]==0)
			B[1]=0;
		else	
			B[1]=1;
	}			
			
	for(int j=2;j<N;j++)
	{
		if(A[j]==0)
			B[j]=B[j-2];
		else if((10*A[j-1]+A[j])>26 || A[j-1]==0)
			B[j]=B[j-1];
		else	
			B[j]=B[j-2]+B[j-1];			
	}
	
	return B[N-1];
}	

int main()
{
	string str;
	char c;
	while(true)
	{
		getline(cin,str);
		c=str[0];
		if(atoi(&c)==0)
			break;
		vector<int> A;	
		for(int i=0;i<str.size();i++)
		{
			c=str[i];
			A.push_back(atoi(&c));
		}

		cout<<codenum(A)<<endl;
	}

	return 0;
}			
	

						
