#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>

#define ll long long

using namespace std;

ll int f[10000]={0};

int main()
{
	f[1]=1;f[2]=1;f[3]=1;
	int i,j,n;
	while(~scanf("%d",&n))
	{
	for(i=4;i<=n;i++)
	{
		f[i]=2*f[i-1]+3*f[i-2]+5*f[i-3];
	}
	
	cout<<f[n]<<endl;
	}
	
	
	return 0;
}







