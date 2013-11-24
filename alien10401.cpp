#include<iostream>
#include<stdio.h>
using namespace std;

struct station
{
	int sum;
	int start;
	station(int s1=0,int s2=0):sum(s1),start(s2){} 
};	

void train(int* A,const int N,const int target, int& ppl,int& stns)
{
	
	station* W=new station[N];
	//Initialize
	(W[0]).sum=A[0];
	(W[0]).start=0;
	int newsum;
	int start_pt=0;
	for(int i=1;i<N;i++)
	{
		newsum=(W[i-1]).sum+A[i];
		if(newsum<=target)
		{
			(W[i]).sum=newsum;
			(W[i]).start=(W[i-1]).start;
		}	
		else
		{
			while(newsum>target && start_pt<i)
			{
				newsum=newsum-A[start_pt];
				start_pt++;
			}
			(W[i]).sum=newsum;
			(W[i]).start=start_pt;
		}
	}		
	int length;				
	stns=0;
	ppl=target;
	//for(int i=0;i<N;i++)
	//	cout<<W[i].sum<<endl;
	
	for(int i=0;i<N;i++)
	{
		length=i-(W[i]).start+1;
		
		if(length==stns)
		{
			if(W[i].sum<ppl)
			{
				stns=length;
				ppl=(W[i]).sum;
			}
		}		
				
		if(length>stns)
		{
			stns=length;
			ppl=(W[i]).sum;
		}
	}
	
	delete[] W;
	return;
}			

int main()
{
	int T;
	scanf("%d",&T);
	int At,Bt;
	int ppl,stns;
	for(int i=0;i<T;i++)
	{
		scanf("%d",&At);
		scanf("%d",&Bt);
		
		int* A=new int[At];
		for(int j=0;j<At;j++)
			scanf("%d",&A[j]);
		train(A,At,Bt,ppl,stns);
		printf("%d %d\n",ppl,stns);
		delete[] A;
	}		
	return 0;
}	
