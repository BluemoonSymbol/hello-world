#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef struct 
{
	double xjb;
	int j,f;
}shao;


int cmp(const shao &x,const shao &y)
{
	return x.xjb<y.xjb;
}

int main()
{
	int i,j,k,m,n;
	while(1)
	{
	cin>>m>>n;
	if(m==-1&&n==-1)
	{
		break;
	}
	shao a[n+1];
	for(i=1;i<=n;i++)
	{
		cin>>a.j>>a.f;
		a.xjb=(double)a.f/a.j;
	}
	sort(a+1,a+1+n,cmp);
	
	double count=0;
	}
	
	
	return 0;
}






