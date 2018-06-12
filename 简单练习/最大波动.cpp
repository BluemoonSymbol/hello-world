#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int i,j,k,n;
	int a[1000]={0};
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int b[1000]={0};
	for(i=1;i<=n-1;i++)
	{
		b[i]=abs(a[i+1]-a[i]);
	}
	sort(b+1,b+n+1);
	cout<<b[n];
	
	
	return 0;
 } 
 
 
 
