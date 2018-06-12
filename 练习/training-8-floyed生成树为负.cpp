#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>

#define INF  999999
using namespace std;
int n,m,w,i,j,k,s,e,t;
int d[505][505];


int F()
{
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
				
					int tmp=d[i][k]+d[k][j];
					if(d[i][j]>tmp)
					{
						 d[i][j]=tmp;
					}  	
				}
				
				if(d[i][i]<0)
				{
					printf("YES\n");
					return 1;
				}
				
			}
		}
	return 0;
	
}


int main()
{
	int f;
	cin>>f;
	while(f--)
	{
	
	
	cin>>n>>m>>w;
		memset(d,INF,sizeof(d));
		for(i=1;i<=n;i++)
		{
			d[i][i]=0;
		}
			
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&s,&e,&t);
			if(t<d[s][e])
			{
				d[s][e]=t;
				d[e][s]=t;	
			}
			
		}
		
		for(i=1;i<=w;i++)
		{
			scanf("%d%d%d",&s,&e,&t);
			d[s][e]=(-1)*t;	
		}
		int l=F();
		if(l==0)
		{
			printf("NO\n");
		
		}
		
}
 return 0;
}

