#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int a[22]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152};
long long  dp[1000001][21]={0};
long long  f(int n,int k)
{
	if(dp[n][k]!=0)
	{
		return dp[n][k];
	}
	else
	{
		if(n==1||k==0)
		{
		dp[n][k]=1;
			return dp[n][k];
		}
		else if(n<a[k])
		{
		
			dp[n][k]=f(n,k-1)%1000000000;
			return dp[n][k];
		}
		else
		{
			dp[n][k]=(f(n,k-1)+f(n-a[k],k))%1000000000;
			return dp[n][k];
		}
	}
}


int find(int n)
{
	int i;
	for(i=0;;i++)
	{
		if(i>20)
		{
			return 20;
		}
		
		if(a[i]>=n)
		{
			return i;
		}
		
	}
	
	
}

int main()
{
	int n=1,k=0;
	cin>>n;
	k=find(n);
	long long tmpp=f(n,k-1);
	cout<<tmpp<<endl;
	

return 0;
}
