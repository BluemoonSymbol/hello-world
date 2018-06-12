#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>

#define ll long long

using namespace std;

ll s[100]={0};

int main()
{
	int n;
	s[1]=1;s[2]=2;s[3]=3;s[4]=4;
	int i,a=0,b=0,c=0,d=1;
	for(i=1;i<55;i++)
	{	
		s[i]=a+b+c+d;
		d=d+c;
		c=b;
		b=a;
		a=d;
		
	}
	
	
	
	while(~scanf("%d",&n))
	{
		cout<<s[n]<<endl;
	}
	
	
	
	return 0;
}






