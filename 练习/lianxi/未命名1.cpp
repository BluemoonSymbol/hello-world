#include<stdio.h>
#include<string.h>


int main()
{
	int n,i,j=1,k;
	scanf("%d",&n);
	int a[1001]={0};
	for(i=1;i<=n;i++)
	{
		scanf("%d",a[i]);
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[i]<a[j])
			{
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
				
			}
			
		}
		
		
	}
	
	int count=1;
	for(i=1;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			count++;
		}
		
	}
	
	int b[1000]={0};
	for(i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			b[j]++;
		}
		if(a[i]!=a[i+1])
		{
			b[j]++;
			j++;
		}
		
	}
	
	for(i=1;i<=count;i++)
	{
		printf("")
	}
	
	
	return 0;
 } 
