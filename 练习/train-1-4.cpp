#include <cstdio>
#include<iostream>
#include <algorithm>
using namespace std;

#define maxn 10001

int main()
{	
	int n,m,ans,a[maxn],j,k,i;
	cin>>n>>m;
	
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	int top=1,tail=n;
	while (top<tail)
	{
		if(a[top]+a[tail]<=m)
		{
			top++;
			tail--;
		}
		else
		{
			tail--;
			++ans;
		}
		
	}
	if (tail==top)
	{
		++ans;
	}
		
	cout<<ans;
	return 0;
}

