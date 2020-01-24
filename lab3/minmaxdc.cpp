#include<bits/stdc++.h>

using namespace std;

int n;
int a[1000001];
int mini = INT_MAX;
int maxi = 0;

void minmax(int st,int end)
{
	if((end-st == 1)||(end-st == 0))
	{
		mini = min(mini,a[st]);
		mini = min(mini,a[end]);
		maxi = max(maxi,a[st]);
		maxi = max(maxi,a[end]);
		return;
	}
	minmax(st,(st+end)/2);
	minmax(((st+end)/2)+1,end);
}


int main()
{
	cout<<"Give the size of array"<<endl;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	minmax(1,n);
	cout<<"Minimum-"<<mini<<endl;
	cout<<"Maximum-"<<maxi<<endl;
}
