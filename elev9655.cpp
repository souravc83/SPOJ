#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;


int main()
{
	int u, d, floor,start,goal;
	scanf("%d",&floor);
	scanf("%d",&start);
	scanf("%d",&goal);
	scanf("%d",&u);
	scanf("%d",&d);
	
	if(start==goal)
	{
		printf("%d\n",0);
		return 0;
	}	
	int* A=new int[floor];
	for(int i=0;i<floor;i++)
		A[i]=-1;

	//Initialize
	queue<int> Q1;
	
	Q1.push(start-1);
	A[start-1]=0;
	int up,down;
	int c1;
	while(!Q1.empty())
	{
		c1=Q1.front();
		Q1.pop();
		up=c1+u;
		if(up<floor && A[up]==-1)
		{
			A[up]=A[c1]+1;
			if (up==(goal-1))
				break;
			Q1.push(up);
		}
		down=c1-d;
		if(down>=0 && A[down]==-1)
		{
			A[down]=A[c1]+1;
			if(down==(goal-1))
				break;
			Q1.push(down);
		}
	}		
				
		
	if(A[goal-1]!=-1)
	{
		printf("%d\n",A[goal-1]);
	}
	else
	{
		printf("use the stairs\n");
	}
	
	delete[] A;
	return 0;
}			
