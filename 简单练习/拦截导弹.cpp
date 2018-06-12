#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int a[100]={0},h[100]={0};

int main()
{
	
	int n,i,j,k,mx=0,po=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	a[1]=1;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=i-1;j++)
		{
			if(mx<a[j])
			{
				mx=a[j];
				po=j;
			}
			if(mx==a[j])
			{
				if(h[j]>h[po])
				{
					po=j;
				}
			}			
		}
		if(h[po]>=h[i])
		{
			a[i]=mx+1;
		}
		else
		{
			a[i]=mx;
		}
	}
	
	sort(a+1,a+n+1);


	
	cout<<a[n]-1;
	return 0;
}


