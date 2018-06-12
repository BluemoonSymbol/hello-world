

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;  
const int N = 250;
const int INF = 999999;
int n, m;
int map[N][N], vis[N], d[N];

int dijkstra(int s, int e)
{    
    for(int i=1; i<=n; i++) 
	{
        d[i] = map[s][i]; 
        vis[i] = 0;
    }

    d[s] = 0;
    vis[s] = 1;    

    for(int i=1; i<=n; i++)
	{
        int tmp, dd=INF;    
        for(int j = 1; j <= n; j++)
		{    
            if(!vis[j] && d[j]<=m)
			{    
                dd=d[j];    
                tmp=j;    
            }    
        }     
        vis[tmp] = 1;    
        for(int j = 1; j <= n; j++)
		{    
            if(!vis[j])
			{    
                d[j]=min(d[j],d[tmp]+map[tmp][j]);    
            }    
        }    
    }
    
     return d[e];         
} 
int main()
{  
    while(~scanf("%d%d",&n,&m)&&n+m)
	{  

	memset(map,0,sizeof(map));
	memset(d,0,sizeof(d));
	memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++)
		{
            for(int j=1; j<=n; j++)
			{
				if(i==j)
				{
					map[i][j]=0;
				}
				else
				{
					map[i][j]=INF;
				}
                  
            }
        }
        int u, v, w;
        for(int i=1; i<=m; i++)
		{  
            scanf("%d%d%d",&u,&v,&w); 
            if(w<map[u][v])
            {
            	map[u][v]=w;
				map[v][u]=w;
			}
                
        }
         

        int s=0, e=0;

        

        int ans = dijkstra(1,n);  

        printf("%d\n",ans);  
	}
	return 0;
   }
