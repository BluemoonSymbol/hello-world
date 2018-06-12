#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;
int dp[30][50000]={0};
int v[30]={0},w[30]={0},vw[30]={0};
int main()
{
	int n,m;
	cin>>n>>m;
	int i,j,k;
	for(i=1;i<=m;i++)
	{
		cin>>v[i]>>w[i];
		vw[i]=v[i]*w[i];
	}
	
//	for(i=1;i<=m;i++)
//	{
//		cout<<v[i]<<"   "<<w[i]<<"     "<<vw[i]<<endl;
//	}
	
	for(i=1;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			
			if(v[i]<=j)
			{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+vw[i]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
			
		}
			
	}
	cout<<dp[m][n]<<endl;
	return 0;
}
