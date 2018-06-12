#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;   

int map[105][105],dis[105][105];  
int main()  
{  
int i,j,k,n,cas,u,v=1;
	while(~scanf("%d%d",&u,&v))
	{
		
		map[u][v]=1; 
		if(v==0&&u==0)
		{
			break;
		}
		
	else 
	{	
			for (int i = 0;i<105;i++)
			{
				for (int j = 0;j<105;j++) 
			{
				map[i][j]=(i==j)?0:999999; 
			 } 
			  }  
            
                 
			while(scanf("%d%d",&u,&v)&&u+v)
			{
				map[u][v]=1;
				n = max(u,n);  
            	n = max(v,n);  
			}
			
		    for(k=1;k<=n;k++)  
		    {  
		        for(i=1;i<=n;i++)  
		        {  
		            for(j=1;j<=n;j++)  
		            {  
		                if(map[i][j]>map[i][k]+map[k][j])  
		                    map[i][j]=map[i][k]+map[k][j];  
		            }  
		        }  
		    } 
		     double cnt = 0,sum=0;  
		    for (int i = 1;i<=n;i++)  
            for (int j = 1;j<=n;j++)  
                if (map[i][j]<999999&&map[i][j])  
                {  
                    sum+=map[i][j];  
                    cnt++;  
                }  
        printf("Case %d: ",cas);  
        cas++;
        printf("average length between pages = %.3lf clicks\n",sum/cnt);  
		    
	}
			
		}
		
    
	
	
	 
} 
