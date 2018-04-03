#include<stdio.h>
#include<string.h>
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a[1001]={0};
	a[0]=0;
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int sum=0;int c1=0,c2=0;int x=0;
	for(i=1;i<=n;i++)
	{
		c1++;
		sum+=a[i];
			x=sum;
		if(sum>=k)
		{
			
			c2++;
			
			sum=0;
		}
			
	}
	if(c1==n&&sum<k&&x<k)
	{
		c2++;
	}
	printf("%d",c2);
	return 0;
}
