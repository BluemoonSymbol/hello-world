#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int a[105][105]={0};


int main()
{
	int i,j;
	for(i=1;i<=101;i++)
	{
		a[i][1]=1;
		a[i][i]=1;	
	}
	for(i=1;i<=101;i++)
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
		cout<<a[n][k]<<endl;
	}
	
	
	return 0;


}
