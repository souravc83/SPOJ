#include<iostream>
#include<stdio.h>
#include<bitset>
#include<math.h>
using namespace std;

//M is possible no. of locations
// K is no. of restaurants to be set up
//N is no. of solitairs.



int gosper(int x)
{
	int y = x & -x;
	int c = x + y;
	x = (((x ^ c) >> 2) / y) | c;
	return x;
}


class location
{
	public:
	int x_c;
	int y_c;
	bitset<100> delivery;
};

class solit
{
	public:
	int x_c;
	int y_c;
	int S;
};

bool dist(location& loc1, solit& sol1,const int& R)
{
	if((pow((loc1.x_c -sol1.x_c),2) + pow((loc1.y_c-sol1.y_c),2))<=R*R)
		return true;
	else
		return false;
}


int deliv_cover(location* loc1,solit* sol1,const int& index,const int& location_size, const int& N)
{
	bitset<100> union_loc;
	for(int i=0;i<location_size;i++)
	{
		if(index&(1<<i))
			union_loc=union_loc|loc1[i].delivery;
	}
	int people=0;
	
	for(int i=0;i<N;i++)
	{
		if(union_loc.test(i))
			people+=sol1[i].S;
	}
	return people;
}

	

int max_delivery(location* locate,const int& location_size, const int& K, solit* sol1, const int& solit_size,const int& R_dist)
{

	for(int i=0;i<location_size;i++)
	{
		for(int j=0;j<solit_size;j++)
		{
			if(dist(locate[i],sol1[j],R_dist))
				(locate[i].delivery).set(j,true);
		}
	}
	
	
	int index=(1<<K)-1;
	int maxindex=1<<(location_size);
	int maxpeople=0;
	int curr_people;
	while(index<maxindex)
	{
		curr_people=deliv_cover(locate,sol1,index,location_size,solit_size);
		if(curr_people>maxpeople)
			maxpeople=curr_people;
		index=gosper(index);
	}
	
	return maxpeople;
}
	
		

int main()
{
	
	//Input
	int K,R;
	scanf("%d %d",&K,&R);
	int location_size;
	scanf("%d",&location_size);
	
	location* loc1=new location[location_size];
	//Read possible restaurant locations
	for(int i=0;i<location_size;i++)
		scanf("%d %d",&loc1[i].x_c,&loc1[i].y_c);
		 	
	int solit_size;
	scanf("%d",&solit_size);
	solit* sol1=new solit[solit_size];
	for(int i=0;i<solit_size;i++)
		scanf("%d %d %d",&sol1[i].x_c,&sol1[i].y_c,&sol1[i].S);
	
	printf("%d\n",max_delivery(loc1,location_size,K,sol1,solit_size,R));
	
	delete[] loc1;
	delete[] sol1;
	
	return 0;
}
		
