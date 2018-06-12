#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;
 
  
int a[355][355]={0};
int dp[355][355]={0};  
  
 
  
int main()  
{  
    int n,i,j,k;  
    cin>>n; 
  
    for (i=1; i<=n; i++)  
    {  
        for (j=1; j<i+1; j++)  
        {  
            cin>>a[i][j]; 
			dp[i][j]=a[i][j]; 
        }  
    }  
  	
    for (i=n-1; i>=1; i--)  
    {  
        for (j=1; j<=i+1; j++)  
        { 
		  dp[i][j]=a[i][j];
          dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);  
        }  
    }  
  
    cout<<dp[1][1];  
  
    return 0;  
} 
