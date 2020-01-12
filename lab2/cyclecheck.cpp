#include<bits/stdc++.h>

using namespace std;

void cycler(int vis[],int i,int j,int n);

int a[1000][1000];

int main()
{
	int n;
	cout<<"Give the total number of nodes"<<endl;
	cin>>n;
	int vis[n+1];
	for(int i = 0;i<=n;i++)
	{
		vis[i] = 0;
	}
	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<=n;j++)
		{
			a[i][j] = 0;
		}
	}
	cout<<"Give the no of edges"<<endl;
	int e;
	cin>>e;
	for(int i = 0;i<e;i++)
	{
		int p,q;
		cout<<"Starting and ending node"<<endl;
		cin>>p>>q;
		a[p][q] = 1;
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(a[i][j] == 1)
			{
				if(vis[i] == 0)
				{
					vis[i] = 1;
					cycler(vis,i,j,n);
				}
			}
		}
	}
}

void cycler(int vis[],int i,int j,int n)
{
	if(i == j)
	{
		cout<<"cycle found"<<endl;
		return;
	}
	if(vis[j] == 0)
	{
		vis[j] = 1;
		for(int k = 1;k<=n;k++)
		{
			if(a[j][k] == 1)
			{
				if(vis[k] == 0)
				{
					cycler(vis,j,k,n);
				}
				else if(vis[k] == 1)
				{
					cout<<"cycle found"<<endl;
					return; 
				}
				else
				{
					return;
				}
			}
		}
	}
	return;
}	
