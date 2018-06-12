#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n,m,i,j,k,count=0;
	cin>>n>>m;
	int P[n+1]={0};
	int Q[n+1]={0}; 
	for(i=1;i<=n;i++)
	{
		cin>>P[i];
	}
	sort(P+1,P+n+1);	
	for(i=n;i>0;i--)
	{	
		if(Q[i]==0)
		{
			
			for(j=i-1;j>0;j--)
			{
				if(Q[j]==0&&Q[i]==0)
				{ 
				 
					if(P[i]+P[j]<=m)
					{
						count++;
						Q[i]=1;
						Q[j]=1;
						goto fk;
					}			
				}
			} 	
		}		
		
		if(Q[i]==0)
		{
			Q[i]=1;
			count++;
		}
		fk:{};	
	} 
	cout<<count;	
	return 0;
}
