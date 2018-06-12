#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

long long int a[50007]={0};

int main()
{
	int n;
	cin>>n;
	int i,j,k;
	long long int ans=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}	
	long long int tt=0,mn=0;
	for(i=1;i<=n;i++)
	{
		
		ans+=a[i];
		if(ans<0)
		{
			mn=	min(mn,ans);
		}
		
	
		
		
	}	
		cout<<-mn;
	
	return 0;
}
