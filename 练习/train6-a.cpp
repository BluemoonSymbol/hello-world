#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;
int a[1004]={0};
int main()
{
	int i,j,k,n;
	while(~scanf("%d",&n))
	{
		if(n==0)break;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		
//		for(i=1;i<=n;i++)
//		{
//			cout<<a[i]<<" ";
//		}
	//	cout<<endl;
		int pre=a[1],sum=a[1];
		if(n==1)
		{
			printf("%d\n",sum);
			continue;
		}
		for(i=2;i<=n+1;i++)
		{
			
			if(a[i]<=pre||i==n+1)
			{
				printf("%d\n",sum);
				break;
			}
			if(a[i]>pre)
			{
				sum+=a[i];
				pre=a[i];
				
			}
			
		}
		
		
	}	
	
	
	return 0;
}


