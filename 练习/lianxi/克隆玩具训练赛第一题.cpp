#include<stdio.h>
 int main()
{
 	int x,y;
	scanf("%d%d",&x,&y);
	if(x<0||x>1000000000||y<=0||y>1000000000||y-x>1)
	{
		printf("No");
		return 0;
	}	
	
	if(y==1&&x!=0)
	{
		printf("No");
		return 0;
	}
 	if((x-y+1)%2==0)
 	{
 		printf("Yes");
	 }
 	else
 	{
 		printf("No");
	 }
 	
 	return 0;
} 
