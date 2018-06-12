#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int i,j,k,count=0,n;
	cin>>n;
	int a[1000]={0};
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=2;i<=n-1;i++)
	{
		if(a[i]>a[i+1]&&a[i]>a[i-1])
		{
			count++;
		}
		if(a[i]<a[i+1]&&a[i]<a[i-1])
		{
			count++;
		}
	}
	cout<<count;
	
	return 0;
	
}


