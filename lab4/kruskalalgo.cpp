#include<bits/stdc++.h>
#include<time.h>

using namespace std;

struct ss
{
	int st;
	int end;
	int we;
};
	
bool cmp(ss a,ss b)
{
	return(a.we<b.we);
}

int main()
{
	cout<<"Give the number of nodes"<<endl;
	int n;
	cin>>n;
	cout<<"Give the total number of edges"<<endl;
	int ed;
	cin>>ed;
	vector<ss> v;
	set<int> ser;
	for(int i = 1;i<=ed;i++)
	{
		int s,e;
		cout<<"Give starting and ending edge"<<endl;
		cin>>s>>e;
		cout<<"Give weight"<<endl;
		int w;
		cin>>w;
		ss* t = new ss;
		t->st = s;
		t->end = e;
		t->we = w;
		v.push_back(*t);
	}
	int sum = 0;
	clock_t start = clock();
	sort(v.begin(),v.end(),cmp);
	//for(vector<ss>::iterator it = v.begin();it!=v.end();it++)
	//{
	//	cout<<"st-"<<it->st<<" end-"<<it->end<<" weight-"<<it->we<<endl;
	//}
	for(vector<ss>::iterator it = v.begin();it!=v.end();it++)
	{
		if(ser.size() == 0)
		{
			ser.insert(it->st);
			ser.insert(it->end);
			sum+=it->we;
		}
		else
		{
			if(ser.find(it->st)!=ser.end()&&ser.find(it->end)!=ser.end())
			{
				it->we = 0;
				continue;
			}
			else
			{
				ser.insert(it->st);
				ser.insert(it->end);
				sum+=it->we;
			}
		}
	}
	clock_t end = clock();
	for(vector<ss>::iterator it = v.begin();it!=v.end();it++)
	{
		cout<<"st-"<<it->st<<" end-"<<it->end<<" weight-"<<it->we<<endl;
	}
	cout<<"Sum- "<<sum<<endl;
	double d = 0.0;
	d += double(double(end-start)/double(CLOCKS_PER_SEC));
	cout<<d<<endl;
}
