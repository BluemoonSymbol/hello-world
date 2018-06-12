#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

int a[1000][1000]={0},lis[1000]={0};

int main()
{
	int n;
	cin>>n;
	int i,j,k,big=0,pre;
	for(i=1;i<=n;i++)
	{
		cin>>lis[i];
		if(lis[i]>big)
		{
			big=lis[i];
		}
	}
	for(i=1;i<=n;i++)
	{
		a[i][i]=lis[i];
	}	
	for(i=n;i>=1;i--)
	{
		for(j=i+1;j<=n;j++)
		{
			a[i][j]=a[i][j-1]+a[i+1][j]-a[i+1][j-1];
			if(a[i][j]>big)
			{
				big=a[i][j];
			}
		}
		
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<big<<endl;
	return 0;
}



