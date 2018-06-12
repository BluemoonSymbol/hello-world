#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int main() 
{
	int a[1000]={0},n,k,i,j;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];	
	}	
	int tmp=0,count=0;
	for(i=1;i<=n;i++)
	{
		tmp+=a[i];
		if(tmp>=k||i==n)
		{
			count++;
			tmp=0;
		}
		
	}
	cout<<count;
	
	
	
	
	return 0;
}


