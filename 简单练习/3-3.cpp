#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
using namespace std; 

int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}

int a[1000][1000]={0};
int main()
{
	int m,n;
	cin>>m>>n;
	if(m<=0||n<=0)
	{
		cout<<"NO";
	}
	
	int i,j,k;
	
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
			cout<<a[i][j]<<" ";	
			
		}
		cout<<endl;
	}	
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cout<<a[j][i]<<" ";	
			
		}
		if(i<n)
		{
			cout<<endl;
		}
		
	}
	
	
	return 0;
}



