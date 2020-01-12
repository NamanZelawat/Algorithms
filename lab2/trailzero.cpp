#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cout<<"Give the number for factorial"<<endl;
	cin>>n;
	int temp1 = n;
	int cnt2 = 0;
	int cnt5 = 0;
	for(int i = 5;(temp1/i)!=0;i*=i)
	{
		int tempo = temp1;
		tempo/=i;
		cnt5+=tempo;
	}
	for(int i = 2;(temp1/i)!=0;i*=i)
	{
		int tempo = temp1;
		tempo/=i;
		cnt2+=tempo;
	}
	cout<<min(cnt2,cnt5)<<endl;
}
