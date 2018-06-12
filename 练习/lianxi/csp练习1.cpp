#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream> 
#define max 101

using namespace std; 

typedef struct point0
{
	int x;
	int y;
}lp;

typedef struct point
{
	int x;
	int y;
}rp;
int a[max][max]={0};

int main()
{
	int n,i,j,k,count=0;
	cin>>n;
	lp s[n];
	rp ss[n];
	for(i=1;i<=n;i++)
	{
		cin>>s[i].x>>s[i].y;
		cin>>ss[i].x>>ss[i].y;
		
		for(j=s[i].x;j<ss[i].x;j++)
		{
			for(k=s[i].y;k<ss[i].y;k++)
			{
				if(a[j][k]==0)
				{
					a[j][k]=1;
					count++;
				}		
			} 	
		}	
	}
	
	for(i=1;i<=n;i++)
	{
		cout<<s[i].x<<'\t'<<s[i].y<<endl;
		cout<<ss[i].x<<'\t'<<ss[i].y<<endl;
	}
	
	
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			printf("%d ",a[i][j]);
			
		}
		printf("\n");
		
	}
	cout<<count;
		
	return 0;
}
