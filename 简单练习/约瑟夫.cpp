#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

char a[100][20];
int c[100]={0};
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
		getchar();
	for(i=1;i<=n;i++)
	{
		scanf("%s",a[i]);
		getchar();
	}	
	int w,s,tmp=0,count=0;
	scanf("%d,%d",&w,&s);tmp=n;
	
	cout<<endl;
//	for(i=1;i<=n;i++)
//	{
//		printf("%s\n",a[i]);	
//	}	
//	cout<<w<<endl<<s<<endl;
//	cout<<endl;
	
	for(i=w;;i++)
	{
		
		if(tmp==0)
		{
			break;
		}
		
		if(i==n+1)
		{
			i=1;
		}
		
		if(c[i]==1)
		{
			continue;
		}
	
		count++;
		if(count==s)
		{
			c[i]=1;
			tmp--;
			printf("%s\n",a[i]);
			count=0;
		}
			
	}
	
	return 0;
}


