#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;  

int map[10000][1000]={0};
int main()
{
	
	int n;int t;
	cin>>n;
	int i,j,k,m;
	for(i=1;i<=n;i++)
	{
		
		cin>>k;
		for(j=1;j<=k;j++)
		{
			cin>>t;
			map[i][t]=1;
			
		}
	}
	
	int q;
	cin>>q;
	while(q--)
	{
		cin>>t;
		for(i=1;i<=n;i++)
		{
			if(map[t][i]==1)
			{
				cout<<i<<" ";
			}
			
		}
		
		cout<<endl;
		
	}
	
	
	return 0;
}


