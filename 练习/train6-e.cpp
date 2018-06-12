#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn=2020;

int dp[maxn][maxn][2]={0};
int p1[maxn],p2[maxn],a[maxn];
 
int main()
{
     int n,i,j,k;
    cin>>n;
     p1[0]=0;p2[n+1]=0;
     for(i=1;i<=n;i++)
	 {
         cin>>a[i];
         p1[i]=p1[i-1];
         if(a[i]==1)
		 {
		 	p1[i]++;
		 }
    }
     for(j=n;j>=1;j--)
	 {
         p2[j]=p2[j+1];
         if(a[j]==2)
		 {
		 	p2[j]++;
		 }
     }
     int ans=0;
     for(i=1;i<=n;i++)
	 {
         for(j=i;j<=n;j++)
		 {
             if(a[j]==2)
			 {
			 	dp[i][j][1]=dp[i][j-1][1]+1;
			 }
             else dp[i][j][1]=dp[i][j-1][1];
             if(a[j]==1)
			 {
			 	dp[i][j][0]=max(dp[i][j-1][0],dp[i][j-1][1])+1;
			 }
             else dp[i][j][0]=max(dp[i][j-1][0],dp[i][j-1][1]);
             ans=max(p1[i-1]+p2[j+1]+dp[i][j][1],max(ans,p1[i-1]+p2[j+1]+dp[i][j][0]));
         }
     }
     cout<<ans<<endl;
}


