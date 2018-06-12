#include<stdio.h>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a[4];
		cin>>a[1]>>a[2]>>a[3];
		sort(a+1,a+4);
		if(a[1]<=0)
		{
			cout<<"Failed"<<endl; 
			continue;
		}
		if(a[1]+a[2]<=a[3])
		{
			cout<<"Failed"<<endl; 
			continue;
		}
		//printf("%d %d %d\n",a[1],a[2],a[3]);
		double s=(double)(a[1]+a[2]+a[3])/2;
		
		
		double S;
		
		
		S=sqrt(s*(s-(double)a[1])*(s-(double)a[2])*(s-(double)a[3]));
		
		printf("%.2lf\n",S);
		
		
	}
	
	
	return 0;
}
