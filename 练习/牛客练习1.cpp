#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
	int s;
	scanf("%d",&s);
	int a=s/3;
	int b=s%3;
	if(b==1)
	{
		b=4;
		a--;
	}
	if(b==0)
	{
		b=1;
	}
	int i,j,k;
	long long  int ans=1,v;
	for(i=1;i<=a;i++)
	{
		ans%=2000000000000000003;
		ans*=3;	
	}
	ans%=2000000000000000003;
	ans*=b;
	ans%=2000000000000000003;
	if(s==1)
	{
		ans=1;
	}
	
	printf("%lld\n",ans);
	}
	
	return 0;
}
