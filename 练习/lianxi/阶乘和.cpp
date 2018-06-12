#include<stdio.h>
#include<time.h>
#define C 30
#define mod 1000000

int f(int n)
{
	if(n==1)
	{
		return 1;
	}
	
	return (n*f(n-1))%mod;
 } 
 
 int main(void)
 {
 	int n,i,j;
 	scanf ("%d",&n);
 	if(n>C)
 	{
 		n=C;
	 }
 	long long int y=n;long long int sum=0;
 	//printf("%d",f(n)); 
 	for(i=n;i>=1;i--)
 	{
 		sum+=f(i);
 		
	 }
 	int x=sum%mod;
 	printf("%d\n",x);
 	printf("Time used=%.2f\n",(double)clock()/CLOCKS_PER_SEC);
 	return 0;
 	
 }
