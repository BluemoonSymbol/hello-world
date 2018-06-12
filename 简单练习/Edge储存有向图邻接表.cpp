#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#define Max 1000005

using namespace std;  

int v[Max]={0},tmp[Max]={0};
int main()
{
	
	int n,t;
	cin>>n;
	int i,j=1,k,m,uu=1,cnt=1;
	
	for(i=1;i<=n;i++)
	{
		cin>>t;	
		tmp[uu]=cnt;
		uu++;
		cnt+=t;	
		
		while(t--)
		{
			
			cin>>v[j];
			j++;
		}		
	}
	
	int q;
	cin>>q;
	while(q--)
	{
		int y;
		cin>>y;
		
		if(y==n)
		{
			for(i=tmp[n];;i++)
			{
				if(v[i]==0)break;
				cout<<v[i]<<" ";
			}
			cout<<endl;
			continue;	
		}
				
		for(i=tmp[y];i<tmp[y+1];i++)
		{
			cout<<v[i]<<" ";	
		}
		cout<<endl;
	}
//	
//	for(i=1;i<=tmp[n]+5;i++)
//	{
//		cout<<u[i]<<" "<<v[i]<<" "<<tmp[i]<<endl;;
//		
//		
//	}
		
	return 0;
}


