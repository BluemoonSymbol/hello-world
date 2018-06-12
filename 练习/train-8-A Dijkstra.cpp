#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;
#define INF 999999

int e[200][200];
int dis[200];
int mark[200];
int n,m;


void Dijkstra(int y)
{ 
    int i,j,k;
    int min;
    int u; 

    
    for(i=0;i<n;i++)
	{
        dis[i]=e[y][i];
    }
    mark[y]=1;


    for(k=0;k<n-1;k++)
	{

        min = INF; 
        for(i=0;i<=n-1;i++)
		{
             
            if(mark[i]==0 && min>=dis[i])
			{
                
                min = dis[i];
                u = i;
            } 
        }

        mark[u]=1;

        
        for(i=0;i<n;i++)
		{
            
            if(e[u][i] < INF)
			{
                
                if(dis[i] > dis[u]+e[u][i])
				{
                    dis[i] = dis[u]+e[u][i];
                } 
            }
        }
    }
  
//    for(i=0;i<n;i++)
//	{
//        printf("%d ",dis[i]);
//    }
    //cout<<endl;
}

int main()
{
    int a,b,c,y;

   while(~scanf("%d%d",&n,&m)) 
   {
   	
   	memset(e,0,sizeof(e));
   	memset(dis,0,sizeof(dis));
   	memset(mark,0,sizeof(mark));
   	
   	
   	for(int i=0;i<n;i++)
	{
        for(int j=0;j<n;j++)
		{
            if(i==j)
			{
                e[i][j]=0;
            }
			else
			{
                e[i][j]=INF;
            }
        }
    }
    
    for(int i=0;i<m;i++)
	{
        scanf("%d%d%d",&a,&b,&c);
        e[a][b]=c;
    }
    
    int hh;
    scanf("%d%d",&y,&hh);
    Dijkstra(y);
	if(dis[hh]!=INF)
	{
		cout<<dis[hh]<<endl;
		continue;
	} 
    else
    {
    	cout<<-1<<endl;
	}
   }
   
    
    
return 0;
}
