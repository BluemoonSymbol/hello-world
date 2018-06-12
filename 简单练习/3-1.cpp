#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#define  ll  long long int
using namespace std;
ll sum(int n)
{
	int i;
	ll s=0;
	for(i=1;i<=n;i++)
	{
		s+=i;
	}
	return s;
}


int main()
{
	int n;
	cin>>n;
	int i;
	ll f=0;
	for(i=1;i<=n;i++)
	{
		f+=sum(i);	
	}
	cout<<f;
	return 0;
}
