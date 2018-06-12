#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;


int n;
int a[20],vis[20];

int Su(int n)           
{
    if(n<2)
    {
    	return 0;
	}
        
    for (int i=2;i*i<=n; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

void dfs(int s)
{
    if(s==n&&Su(a[1]+a[n])) 
    {
        for(int i=1; i<n; i++)
        {
        	cout<<a[i]<<" ";
		}
        
        cout<<a[n]<<endl;
    }
    else
    {
        for(int i=2; i<=n; i++)
        {
            if(vis[i]==0&&Su(i+a[s]))  
            {
                a[s+1]=i;
                vis[i]=1;            
                dfs(s+1);
                vis[i]=0;           
            }
        }
    }
}
int main()
{
	
	int fff[3]={0,9,7};
	sort(fff,fff+3);
	
    int t=0;
    while(cin>>n)
    {
        memset(vis,0,sizeof(vis));
        a[1]=1;
        
		           
        t++;
        cout<<"Case "<<t<<":"<<endl;
        dfs(1);
        if(t!=0)
        {
        	cout<<endl;
		}
    }
    return 0;
}

