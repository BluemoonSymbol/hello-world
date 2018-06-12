#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int a,b,i;
while(scanf("%d%d",&a,&b)!=EOF)
{
	if(a==0)
	{
		printf("0\n");
		continue;
	}
	if(b==0)
	{
		printf("1\n");
		continue;
	}
	if(b==1)
	{
		printf("%d\n",a%10);
		continue;
	}
	
	a=a%10;
    b=b%4+4;
    printf("%d\n",(int)pow(a,b)%10);

}
	
	
	return 0;
}

 
