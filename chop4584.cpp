#include<iostream>
#include<string>
#include<vector>
using namespace std;

void print(const vector<int>& grp)
{
	for(int i=0;i<grp.size();i++)
		cout<<grp[i]<<"-";
	cout<<'\n';
	return;
}

int rec_group(vector<int>& numarr,vector<int> group, int index)
{
	bool isgroup=false;
	int N=group.size();
	if(group.size()==1)
		isgroup=true;
	else if(group[N-1]>=group[N-2])
		isgroup=true;
	if(index==numarr.size())
	{
		if(isgroup==true)
		{
			//print(group);
			return 1;
		}
		else
			return 0;
	}
	
	int count=0;

	//Branch1
	group.back()=group.back()+numarr[index];
	count+=rec_group(numarr,group,index+1);
	//back to original group
	group.back()=group.back()-numarr[index];
	//Branch2
	if(N==1 || group[N-1]>=group[N-2])
	{
		group.push_back(numarr[index]);
		count+=rec_group(numarr,group,index+1);
	}

	return count;
}			
		

int group(string num)
{
	//cout<<num.size()<<'\n';
	vector<int>numarr;
	int N=num.size();
	for(int i=0;i<N;i++)
		numarr.push_back(num[i]-'0');
	//print(numarr);
	vector<int> group;
	group.push_back(numarr[0]);
	return rec_group(numarr,group,1);
}	


int main()
{

	string num;
	int count=0;
	while(1)
	{
		cin>>num;
		//if(num=="bye")
		if((num[0]-'0')<0 ||(num[0]-'0')>9)
			break;
		count++;
		cout<<count<<". "<<group(num)<<'\n';
	}
	return 0;
}
	
		
