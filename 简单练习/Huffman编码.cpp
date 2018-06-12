#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

int a[1000002];

int main()
{
	
	int i,j,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	int k=1,sum=0;
	for(i=1;i<n;i++)
	{
		sort(a+i,a+n+1);
		a[i+1]=a[i]+a[i+1];
		sum+=a[i+1];
	 } 
	
//	for(i=1;i<=n;i++)
//	{
//		cout<<a[i]<<" ";
//		
//	}
//	cout<<endl;
	
	
	cout<<sum<<endl;
	return 0;
}

