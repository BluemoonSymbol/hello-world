#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

int a[1001]={0};  
int dp[1001]={0};  
  
int main(void)
{  
    int i,N,j,k;  
    while (~scanf("%d",&N))
	{ 
	 if(N==0)break;
	 memset(a,0,sizeof(a));
	 memset(dp,0,sizeof(dp));
	 
        for (i=1;i<=N;++i)
		{  
            cin>>a[i];  
        }  
        
        int max=0;  
    for (i=1;i<=N;++i)
	{  
        dp[i] = a[i];  
        for (j=1;j<i;++j)
		{  
            if (a[i]>a[j]&&dp[i]<dp[j]+a[i])
			{  
                dp[i]=dp[j]+a[i];  
            }  
        }  
    }  
 
    for (i = 1; i <= N; ++i)
	{  
        if (max<dp[i])  
            max=dp[i];  
    }  
        
      cout<<max<<endl;       
    }  
    
    return 0;  
} 
