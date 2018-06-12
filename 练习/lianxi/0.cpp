#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<windows.h>

using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[1000]={0};
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]); 	
	}
	
		for(i=1;i<=n;i++)
	{
			if(i==1)
			{
				printf("1 ");
				continue;
			}
			int count=1;
			for(j=1;j<=i;j++)
			{
				if(a[j]==a[i])
				{
					count++;
					
				}
			
			}
			printf("%d ",count);
			
			
	}

	return 0;
	
} 
