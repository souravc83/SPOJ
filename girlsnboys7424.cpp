#include<iostream>
#include<math.h>
using namespace std;


int groups(int R,int C)
{
	if(R==0 && C==0)
		return 0;
		
	int greater,smaller;
	if(R>C)
	{
		greater=R;
		smaller=C;
	}
	else
	{
		greater=C;
		smaller=R;
	}
	if(smaller==0)
		return greater;
	
	float div=greater/float(smaller+1);
	return ceil(div);
}

	
	
		

int main()
{
	int R,C;
	while(1)
	{
		cin>>R>>C;
		if(R==-1 && C==-1)
			break;
		cout<<groups(R,C)<<'\n';	
	}
	return 0;
}
