#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> a[1001];
vector<int> b[1001];

vector<int> mult(vector<int> x[],vector<int> multer[])
{
	int s = multer[1].size();
	vector<int> ans;
	for(int i = 1;i<=s;i++)
	{
		for(int j = 1;j<=s;j++)
		{
			int sum = 0;
			for(int k = 1;k<=s;k++)
			{
				sum+=(x[i][k]*multer[j][k]);
			}
			ans[i].push_back(sum);
		}
	}
	return ans;
}

vector<int> add(int st,int end,vector<int> x[],vector<int> adr[])
{
	int s = adr[1].size();
	vector<int> ans;
	for(int i = 1;i<=s;i++)
	{
		for(int j = 1;j<=s;j++)
		{
			ans[i].push_back(x[i][j]+adr[i][j];
		}
	}
	return ans;
}
	
void assig(vector<int> x[],vector<int> asgn[])
{
	int s = asgn[1].size();
	for(int i = 1;i<=s;i++)
	{
		for(int j = 1;j<=s;j++)
		{
			x[i].push_back(asgn[i][j]);
		}
	}
}

vector<int> strassen(vector<int> x,vector<int> y)
{
	if(n == 2)
	{
			
	}
	int sx = x[1].size();
	int sy = y[1].size();
	assig(p,strassen(add(1,1,x,y,n/2),add(n/2+1,n/2+1,x,y,n/2)));
	assig(q,strassen(add(n/2+1,1,x,y,n/2),y)
	strassen(1,n/2+1,n/2);
	strassen(n/2+1,n/2+1,n/2);
	strassen(n/2+1,1,n/2);
}

int main()
{
	cout<<"Give the dimension of matrix, should be in power of 2 :)\n"
	cin>>n;
	cout<<"Give the first matrix\n";
	for(int i = 1;i<=n;i++)
	{
		for(int j= 1;j<=n;j++)
		{
			int t;
			cin>>t;
			a[i].push_back(t);
		}
	} 
	cout<<"Give the second matrix\n";
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			int t;
			cin>>t;
			b[i].push_back(t);
		}
	}
	strassen(1,1,n);
}
