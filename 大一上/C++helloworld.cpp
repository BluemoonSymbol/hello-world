#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<windows.h>

using namespace std;


int main()
{
	long long int x,y;
	scanf("%d%d",&x,&y);
	if(y==0||y>1000000000||x>1000000000||x<0||y<0)
	{
		printf("No");
		return 0;
	}
	
	if((x+1-y)%2==0&&x+1-y>=0)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}

	return 0;
}
