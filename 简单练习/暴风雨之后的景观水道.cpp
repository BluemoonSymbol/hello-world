#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

int a[10001]={0};


int main()
{
	int t,i,j,k,x,y,u,v,mx=0;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cin>>x>>y;
		while(y--)
		{
			cin>>u>>v;
			if(v>mx)mx=v;
			for(i=u;i<=v;i++)
			{
				a[i]=1;
			}	
		}
		int cnt=0;
		for(i=1;i<=mx;i++)
		{
			if(a[i]==1)
			{
				cnt++;
			}
		}
		cout<<x-cnt+1<<endl;
		
	}


	
	
	return 0;


}


