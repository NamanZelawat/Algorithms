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
	clock_t start = clock();
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
	vector<ss> st;
	vector<ss> ans;
	for(int i = 1;i<=n;i++)
	{
		for(vector<ss>::iterator it = v.begin();it!=v.end();it++)
		{
			if((it->st == i&&it->end > i)||(it->st > i&&it->end == i))
			{
				st.push_back(*it);
				
			}
		}
		sort(st.begin(),st.end(),cmp);
		vector<ss>::iterator d = st.begin();
		if(ans.size() == 0)
		{
			ans.push_back(*d);
			ser.insert(d->st);
			ser.insert(d->end);
		}
		else
		{
			if(ser.find(d->st)!=ser.end()&&ser.find(d->end)!=ser.end())
			{
				
			}
			else
			{
				ans.push_back(*d);
				ser.insert(d->st);
				ser.insert(d->end);
			}
		}
		st.erase(d);
	}
	clock_t end = clock();
	for(vector<ss>::iterator it = ans.begin();it!=ans.end();it++)
	{
		cout<<"st-"<<it->st<<" end-"<<it->end<<" weight-"<<it->we<<endl;
	}
	double d = 0.0;
	d += double(double(end-start)/double(CLOCKS_PER_SEC));
	cout<<d<<endl;
}
