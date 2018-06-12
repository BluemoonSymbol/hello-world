#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int a[1000002];

int main()
{
	int n,i,j,ans=0;
	cin>>n;
	priority_queue< int, vector<int> ,greater<int> >q;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		q.push(a[i]);
	}
	while(q.size()>1)
	{
		int tmp=0;
		ans+=q.top();
		tmp+=q.top();
		q.pop();
		ans+=q.top();
		tmp+=q.top();
		q.pop();
		q.push(tmp);
		
	}
	
	cout<<ans<<endl;
	
	return 0;
}


