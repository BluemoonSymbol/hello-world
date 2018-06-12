#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>


int vis[100]={0};


int ok(int n)
{
	for(int i=1;i<n;i++)
	{
		if(vis[i]==vis[n]||abs(vis[i] - vis[n]) == abs(n - i))
		{
			return 0;		
		}	
	}
	return 1;	
}

int tot=0;

void dfs(int cur,int n)
{
	int i;
		for(i=1;i<=n;i++)
		{
			vis[cur]=i;
			
			if(ok(cur)==1)
			{ 		
				if(cur==n)
					{
						tot++;	
					}
					else
					{
						dfs(cur+1,n);
					}			
			}			
		}
	
}



int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
	
		tot=0;
		dfs(1,n);
	printf("%d\n",tot);
	
	}
return 0;

} 
 
 
 
