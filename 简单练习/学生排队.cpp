#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

int a[1000]={0};



void move(int a[],int c,int d,int n)
{
	int i,t1=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==c)
		{
			t1=i;
			break;
		}
	}
	
	if(d>0)
	{
		for(i=1;i<=d;i++)
		{
			swap(a[t1],a[t1+1]);
			t1++;
		}	
	}
	if(d<0)
	{
		for(i=1;i<=-d;i++)
		{
			swap(a[t1],a[t1-1]);
			t1--;
		}	
	}
	
}

int main()
{
	int n,m,i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		a[i]=i;
	}
	while(m--)
	{
		int c,d;
		cin>>c>>d;
		move(a,c,d,n);
	}
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
		
	
	return 0;
}


