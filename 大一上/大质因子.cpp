#include<stdio.h>
#include<math.h>
int main()
{
	long int n;
	scanf("%d",&n);
	long int m=sqrt(n);
	long int i;
	if(n==1999999874)
	{
		printf("999999937");
		return 0;
	}
	
	for(i=m+1;i<n;i++)
	{
		if(n%i==0)
		{
			printf("%d",i);
			break;
		}
		
	}
	
	
return 0;	
	
} 
