#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std; 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
			
		int n;
		cin>>n;
		int ma[n+1];
		int i,j,k;
		for(i=1;i<=n;i++)
		{
			cin>>ma[i];
			
		}
		
		if(n==1)
		{
			cout<<ma[1]<<endl;
			continue;
		}
		
		if(n==2)
		{
			cout<<ma[2]<<endl;
			continue;
		}
		
		int sum=0;
		sort(ma+1,ma+1+n);
		
		if(n%2==0&&n>2)
		{
			
			for(i=n;i>=4;i-=2)
			{
			sum+=min(ma[i]+2*ma[2]+ma[1],ma[i]+ma[i-1]+2*ma[1]);
				
			}
			sum+=ma[2];
		}
		
		
		if(n%2==1&&n>2)
		{
			
			for(i=n;i>3;i-=2)
			{
				sum+=min(2*ma[2]+ma[1]+ma[i],ma[i]+ma[i-1]+2*ma[1]);//每一步选最优，而不是总体！ 
			}
			sum+=ma[1]+ma[2]+ma[3];
		} 
		

	cout<<sum<<endl;	
	}
	
	return 0;
}




