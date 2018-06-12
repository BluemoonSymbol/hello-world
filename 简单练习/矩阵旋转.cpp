#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int a[11][11]={0},b[11][11]={0};


int main()
{
	
	int n,i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];	
		}	
	}
	
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>b[i][j];
		}
	}
	
	int count=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==b[i][j])
			{
				count++;
			}
		}
	}
	if(count==n*n)
	{
		cout<<"0"<<endl;
		return 0;
	}
	
	
	
	count=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==b[j][n+1-i])
			{
				count++;
			}
		}
	}
	if(count==n*n)
	{
		cout<<"90"<<endl;
		return 0;
	}
	
	
	
	
	count=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==b[n+1-i][n+1-j])
			{
				count++;
			}
		}
	}
	if(count==n*n)
	{
		cout<<"180"<<endl;
		return 0;
	}
	
	
	
	count=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==b[j][n+1-j])
			{
				count++;
			}
		}
	}
	if(count==n*n)
	{
		cout<<"270"<<endl;
		return 0;
	}
	
	
	
	cout<<"-1";
	
	return 0;
}



