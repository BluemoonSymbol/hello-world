#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

long long int Max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	int m,n,i,j,k;
	long long int s1 ,s2 ,ans;
	cin>>n>>m;
	long long int Y[n+1],D[m+1];
	for(i=1;i<=n;i++)
	{
		cin>>Y[i];
	}
	for(i=1;i<=m;i++)
	{
		cin>>D[i];
	}
	
	sort(Y+1,Y+n+1);	
//	for(i=1;i<=n;i++)
//		{
//		cout<<Y[i]<<" ";
//	}
//	cout<<endl;
	sort(D+1,D+m+1);
	
	s1=max(max(Y[2]*D[1],Y[n]*D[m]),max(Y[2]*D[m],Y[n]*D[1]));
	s2=max(max(Y[1]*D[1],Y[n-1]*D[m]),max(Y[1]*D[m],Y[n-1]*D[1]));
	ans=min(s1,s2);
	cout<<ans;
	
//	for(i=1;i<=m;i++)
//	{
//		cout<<D[i]<<" ";
//	}
//	printf("\n");
// long long int max[5];
//	max[1]=D[1]*Y[1];
//	max[2]=D[m]*Y[n];
//	max[3]=D[m]*Y[1];
//	max[4]=D[1]*Y[n];
//	sort(max+1,max+5);
//	
//		for(i=1;i<=4;i++)
//	{
//		cout<<max[i]<<" ";
//	}
//	printf("\n");
//	
//	if(max[4]==D[1]*Y[n])
//	{
//		cout<<D[1]*Y[n-1];
//		return 0;
//	}
//	if(max[4]==D[m]*Y[1])
//	{
//		cout<<D[m]*Y[2];
//			return 0;
//	}
//	if(max[4]==D[m]*Y[n])
//	{
//		cout<<Max(D[m]*Y[n-1],D[1]*Y[1]);
//			return 0;
//	}
//	if(max[4]==D[1]*Y[1])
//	{
//		cout<<Max(D[1]*Y[2],D[m]*Y[n]);
//			return 0;
//	}
	return 0;
	
}


