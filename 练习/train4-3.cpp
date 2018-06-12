#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

int g[50]={0};
int main()
{
	while(1)
	{
		g[1]=1;
		g[2]=1;
		
		int a,b,n,i,j;
		cin>>a>>b>>n;
		if(a==0&&b==0&&n==0)
		{
			break;
		}
		//cout<<"1:1"<<endl<<"2:1"<<endl;
		for(i=3;i<=48;i++)
		{
			g[i]=(a*g[i-1]+b*g[i-2])%7;
			
		}
		int m=n%48;
		cout<<g[m]<<endl;
		
		
	}
	
	
	
	return 0;
 } 
 
 
 
 
