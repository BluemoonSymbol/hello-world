#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,i,j,k;
		cin>>n>>m;
		if(n==m&&n%2==0)
		{
			cout<<"1"<<endl;
			continue;
		}
		int a=n-m;
		int b=m-1;
		int cnt=1;
		while(1)
		{
			if(n>=2&&a==0&&(n%2==0))
			{
				if(m==1)
				{
					cout<<cnt-1<<endl;
					break;
				}
				cout<<cnt<<endl;
				break;
				
			}
			
			
			if((n%2==1))
			{
				n=(n+1)/2;
				cnt++;
				if((b%2==0)||(a%2==0))
				{
					b/=2;
					a/=2;
					continue;
				}
				if((b%2==1)||(a%2==1))
				{
					b=(b+1)/2;
					a=(a-1)/2;
					continue;
				}
				continue;	
			}
			if((n%2==0))
			{
				if(n>2)
				{
					n/=2;
				}
			
				if((b%2==0)||(a%2==1))
				{
					b/=2;
					a=(a-1)/2;	
					cnt++;	
					continue;
				}
				if((b%2==1)||(a%2==0))
				{
					b=(b+1)/2;
					a=(a-2)/2;	
					cnt++;	
					continue;
				}
				continue;
				
			}
			
			
		}
		
		
	}
	
	
	
	
	return 0;
}
