#include<stdio.h>  
#include<iostream>  
#include<cmath>
#include<cstring>
#include<algorithm>  

using namespace std;  

typedef struct 
{
	double j,f;
	double D;
}shao;

int cmp(const shao a,const shao b)
{
	
	return a.D<b.D;

}





int main()
{
	int m,n;
	cin>>m>>n;
	shao a[n+1];
	int i,k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].j>>a[i].f;
		a[i].D=a[i].f/a[i].j;
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		cout<<a[i].D<<" "<<a[i].f<<" "<<a[i].j<<endl;
	}
	return 0;
}





