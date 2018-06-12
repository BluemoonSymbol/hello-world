#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

char ma[102][102],mb[102][102];
int vis[100][100]={0};

int dfs(int i,int j)
{
	if(vis[i][j]==1||mb[i][j]=='*')
	{
		return 0;
	}
	vis[i][j]=1;  
    dfs(i-1,j-1);  
    dfs(i-1,j);  
    dfs(i-1,j+1);  
    dfs(i,j-1);  
    dfs(i,j+1);  
    dfs(i+1,j-1);  
    dfs(i+1,j);  
    dfs(i+1,j+1);
	
}

int main()
{
	int i,j,k;
		int m,n;
	while(~scanf("%d %d",&m,&n)&&n&&m)
	{	
		memset(ma,0,sizeof(ma));
		memset(mb,'*',sizeof(mb));
		memset(vis,0,sizeof(vis));
		
		for(i=0;i<m;i++)
		{
			
			scanf("%s",&ma[i]);
			for(k=1;k<=n;k++)
			{
				mb[i+1][k]=ma[i][k-1];
			}
	
		}

		int count=0;
		for(i=1;i<=m;i++)  
        {  
            for(j=1;j<=n;j++)  
            {  
                if(vis[i][j]==0&&mb[i][j]=='@')  
                {  
                    dfs(i,j);  
                    count++;  
                }  
            }  
        }  
           
       printf("%d\n",count);  
    }  
  return 0;  
	
}






