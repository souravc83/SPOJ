#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
;
	int Acount[1000000];
	int Dcount[1000000];

int sextuples(int* S,const int N)
{
	int ABC[1000000];
	int DEF[1000000];
	int k;
	int szA=0;
	int szB=0;
	for(int a1=0;a1<N;a1++)
	{
		for(int b1=0;b1<N;b1++)
		{
			for(int c1=0;c1<N;c1++)
			{
				k=S[a1]*S[b1]+S[c1];
				ABC[szA++]=k;
			}
		}
	}


	for(int d1=0;d1<N;d1++)
	{
		if(S[d1]!=0)
		{
			for(int e1=0;e1<N;e1++)
			{
				for(int f1=0;f1<N;f1++)
				{
					k=S[d1]*(S[e1]+S[f1]);
					DEF[szB++]=k;
				}
			}
		}
	}

	std::sort(DEF,DEF+szB);
	std::sort(ABC,ABC+szA);

	long long count=0;

	int Aind=0;
	int Dind=0;

	Acount[0]=1;
	Dcount[0]=1;

	for(int i=1;i<szA;i++)
	{
		if(ABC[i]==ABC[Aind])
			Acount[Aind]+=1;
		else
		{
			Acount[i]+=1;
			Aind=i;
		}
	}

	for(int i=1;i<szB;i++)
	{
		if(DEF[i]==DEF[Dind])
			Dcount[Dind]+=1;
		else
		{
			Dcount[i]+=1;
			Dind=i;
		}
	}

	Dind=0;
	Aind=0;
	int lastno;
	for(int i=0;i<szA;i++)
	{
		if(i>0 && ABC[i]==lastno)
			continue;
		else
			lastno=ABC[i];
		while(Dind<szB && ABC[i]>DEF[Dind])
		{
			Dind++;
		}

		if(Dind<szB && ABC[i]==DEF[Dind])
		{
			count=count+(long long)Acount[i]*Dcount[Dind];
		}
	}

	return count;
}

int main()
{
	int N;
	cin>>N;
	 int S[100]={0};
	int k;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&k);
		S[i]=k;
	}
	cout<<sextuples(S,N)<<endl;

	return 0;
}
