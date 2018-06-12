#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>

#define INF  9999999
using namespace std;

int i,j,k,p,r,s,e,t; 
int d[1000][1000];

int prime()  
{  
  bool vis[1000];  
  int dist[1000];  
    int i,j,sum=0;  
  for(i=1;i<=p;i++)  
  {  
    vis[i]=0;  
   
    dist[i]=d[1][i];  
  }  
  vis[1]=1;  
  for(i=1;i<p;i++)  
  {  
    int k,min=INF;  
    for(j=1;j<=p;j++)  
    {  
      if(!vis[j]&&dist[j]<min)  
      {  
        min=dist[j];  
        k=j;  
      }  
    }  
     
    sum+=dist[k];  
    vis[k]=1;  
    
    for(j=1;j<=p;j++)  
    {  
      if(!vis[j]&&dist[j]>d[k][j])  
        dist[j]=d[k][j];  
    }  
  }  
  return sum;  
}  

int main()
{
	
	while(~scanf("%d",&p))
	{
		if(p==0)
		{
			break;
		}
		scanf("%d",&r);
		memset(d,INF,sizeof(d));
		for(i=1;i<=r;i++)
		{
			d[i][i]=0;
		}
			
		for(i=1;i<=r;i++)
		{
			scanf("%d%d%d",&s,&e,&t);
			if(t<d[s][e])
			{
				d[s][e]=t;
				d[e][s]=t;	
			}
			
		}
		
	printf("%d\n",prime());
		
	}
 return 0;
}

