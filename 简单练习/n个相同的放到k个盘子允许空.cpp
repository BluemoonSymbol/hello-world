#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int a[55][55]={0};


int main()
{
	int i,j;
	for(i=1;i<=51;i++)
	{
		a[i][1]=1;
		a[i][i]=1;	
	}
	for(i=1;i<=51;i++)
	{
		for(j=1;j<7;j++)
		{
			if(i>j)
			{
				a[i][j]=a[i-1][j-1]+a[i-j][j];
				continue;
			}
			break;
		}
		
	}
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		int sum=0;
		for(i=1;i<=k;i++)
		{
			sum+=a[n][i];	
		}
		cout<<sum<<endl;
	}
	
	
	return 0;


}
