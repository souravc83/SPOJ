#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct alpha
{
	char name;
	int count;
	int pos;
	char type;
	alpha(char n='a',char t='c',int p=0,int c=0):name(n),pos(p),type(t),count(c){}
};

class table1
{	
	vector<alpha>A1;
	public:
	table1();
	alpha lookup(char);
	void addcount(char);
};

table1::table1()
{
	int vowel=1;
	int conso=1;
	for(int i=97;i<=122;i++)
	{
		char c=i;
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		{
			alpha N1(c,'v',vowel);
			vowel++;
			A1.push_back(N1);
		}	
		else
		{
			alpha N1(c,'c',conso);
			conso++;
			A1.push_back(N1);
		}	
		
		
	}		
}
			
		
alpha table1::lookup(char c)
{
	int x=c-'a';
	return A1.at(x);
}	

void table1::addcount(char c)
{
	int x=c-'a';
	A1.at(x).count++;
	return;
}

class table2
{
	vector<alpha>A2;
	public:
	table2();
	char lookup(int,char);
};

table2::table2()
{
	for(int i=97;i<=122;i++)
	{
		char c=i;
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
			continue;
		else
		{
			alpha N1(c);
			A2.push_back(N1);
		}	
	}	
	alpha N2('a');
	A2.push_back(N2);
	N2.name='e';
	A2.push_back(N2);
	N2.name='i';
	A2.push_back(N2);
	N2.name='o';
	A2.push_back(N2);
	N2.name='u';
	A2.push_back('u');
}	


char table2::lookup(int pos,char x)
{
	alpha N1;
	if(x=='v')
	{
		N1=A2.at(21+pos-1);
		return N1.name;
	}
	else
	{
		N1=A2.at(pos-1);
		return N1.name;
	}
}		

string encrypt(string s1)
{
	table1 T1;
	table2 T2;
	string ans;
	int N=s1.size();
	for(int i=0;i<N;i++)
	{
		char c=s1.at(i);
		alpha N1=T1.lookup(c);
		int k=N1.count;
		int p1=N1.pos;
		char voc=N1.type;
		if(voc=='v')
		{
			int p2=5*k+p1;
			int position=p2%21;
			if (position==0)
				position=21;
			//cout<<position<<endl;
			ans.push_back(T2.lookup(position,'c'));
		}
		else
		{
			int p2=21*k+p1;
			int position=p2%5;
			if (position==0)
				position=5;
			//cout<<position<<endl;	
			ans.push_back(T2.lookup(position,'v'));
		}
		T1.addcount(c);
	}
	return ans;		
}			
			
		
int main()
{
	vector<string>input;
	string k;
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>k;
		input.push_back(k);
	}
	
	for(int i=0;i<N;i++)
	{
		cout<<encrypt(input.at(i))<<endl;
	}
	return 0;
}	
		
		


