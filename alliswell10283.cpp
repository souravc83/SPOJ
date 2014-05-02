#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

bool ismatch(char** M,int R,int C, int row1,int col1,char mchar)
{
	if(row1<0 || col1<0 || row1>=R || col1>=C)
		return false;

	if(M[row1][col1]==mchar)
	{
		//cout<<mchar<<'\n';
		return true;
	}
	else
		return false;
}

bool recur_path(char** M,int R,int C, int curr_row,int curr_col,int str_posn)
{
	
	string target="ALLIZZWELL";
	if(str_posn==target.size())
		return true;
	
	M[curr_row][curr_col]='0';// so that not traversed again

	int rchange[]={-1,0,1};
	int cchange[]={-1,0,1};

	bool result=false;

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==1 && j==1)
				continue;
			if( ismatch(M,R,C,curr_row+rchange[i],curr_col+cchange[j],target[str_posn]))
				result=recur_path(M,R,C,curr_row+rchange[i],curr_col+cchange[j],str_posn+1);
			if(result)
				break;
		}
		if(result)
			break;
	}
	//Restore matrix
	M[curr_row][curr_col]=target[str_posn-1];
	return result;
}

		

string ispath(char** M, int R, int C)
{
	//Read matrix for starting points
	vector<pair<int,int> > start_pt;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(M[i][j]=='A')
				start_pt.push_back(make_pair(i,j));
		}
	}

	if(start_pt.size()==0)
		return "NO";
	vector<pair<int,int> >::iterator it;

	for(it=start_pt.begin();it!=start_pt.end();it++)
	{

		if( recur_path(M,R,C,it->first,it->second, 1))
			return "YES";
	}
	return "NO";
}
			


int main()
{
	int T,R,C;

	cin>>T;
	vector<string> ans;
	char** M;

	for(int i=0;i<T;i++)
	{
		cin>>R;
		cin>>C;
		//Declare matrix
		M=new char*[R];
		for(int i1=0;i1<R;i1++)
			M[i1]=new char[C];

		for(int i1=0;i1<R;i1++)
		{
			for(int j=0;j<C;j++)
				cin>>M[i1][j];
		}
			
		ans.push_back(ispath(M,R,C));

		//delete matrix
		for(int i1=0;i1<R;i1++)
			delete[] M[i1];
		delete[] M;
		
		cin.ignore(256,'\n');
	
	}

	for(vector<string>::iterator it=ans.begin();it!=ans.end();it++)
		cout<<*it<<'\n';

	return 0;
}	
		

		
