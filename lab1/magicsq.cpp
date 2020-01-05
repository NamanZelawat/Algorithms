#include<bits/stdc++.h>

using namespace std;

int main()
{
int n;
cout<<"Give the value of n"<<endl;
cin>>n;
int a[n][n];
for(int i = 0;i<n;i++)
{
	for(int j = 0;j<n;j++)
	{
		a[i][j] = 0;
	}
}
if(n%2!=0)
{
	a[0][n/2] = 1;
	int y = 0;
	int x = n/2;
	int det = 2;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			int tempx= x;
			int tempy = y;
			x-=1;
			y-=1;
			if(x == -1)
			{
				x = n-1;
			}
			if(y == -1)
			{
				y = n-1;
			}
			if(a[y][x] != 0)
			{
				x = tempx;
				y = tempy+1;
			}
			a[y][x] = det;
			det++;
		}
	}
}
else if(n%4 == 0)
{	
	int val = 1;
	int cal = n/4;
	vector<int> rem;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(((i<cal)&&((j<cal)||(j>(n-1-cal))))||((i>n-1-cal)&&((j<cal)||(j>(n-1-cal)))))
			{
				a[i][j] = val;
			}
			else if(((i>=cal)&&(i<=n-1-cal))&&((j>=cal)&&(j<=(n-1-cal))))
			{
				a[i][j] = val;
			}
			else
			{
				rem.push_back(val);
			}
			val++;
		}
	}
	int it = 0;
	for(int i = n-1;i>=0;--i)
	{
		for(int j = n-1;j>=0;--j)
		{
			if(a[i][j] == 0)
			{
				a[i][j] = rem[it];
				it++;
			}
		}
	}
}
else if(n%4 == 2)
{
	a[0][(n/2-1)/2] = 1;
	int y = 0;
	int x = (n/2-1)/2;
	int det = 2;
	for(int i = 0;i<((n/2)*(n/2))-1;i++)
	{
		int tempx= x;
		int tempy = y;
		x-=1;
		y-=1;
		if(x == -1)
		{
			x = (n/2)-1;
		}
		if(y == -1)
		{
			y = (n/2)-1;
		}
		if(a[y][x] != 0)
		{
			x = tempx;
			y = tempy+1;
		}
		a[y][x] = det;
		det++;
	}
	for(int i = 0;i<(n/2);i++)
	{
		for(int j = 0;j<(n/2);j++)
		{
			a[i+(n/2)][j+(n/2)] = a[i][j]+9;
			a[i][j+(n/2)] = a[i][j]+18;
			a[i+(n/2)][j] = a[i][j]+27;
		}
	}
	int k = n/4;
	for(int i = 0;i<n/2;i++)
	{
		if(i == k)
		{
			for(int j = 0;j<k;j++)
			{
				swap(a[i][j+1],a[i+(n/2)][j+1]);
			}
		}
		else
		{
			for(int j = 0;j<k;j++)
			{
				swap(a[i][j],a[i+(n/2)][j]);
			}
		}
	}
	for(int i = 0;i<n/2;i++)
	{
		for(int j = n-1;j>n-1-(k-1);--j)
		{
			swap(a[i][j],a[i+(n/2)][j]);
		}
	}
}
for(int i = 0;i<n;i++)
{
	for(int j = 0;j<n;j++)
	{
		cout<<a[i][j]<<" ";
	}
	cout<<endl;
}
}
