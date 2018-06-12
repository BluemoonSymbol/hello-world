#include<cstdio>
#include<iostream>
using namespace std;


int main()
{int n;
	while(~scanf("%d",&n))
	{
	double a[100]={0,1,2,6},b[100]={0,0,1,2};
	int i,j,k;
	
	
	if(n<=1)
	{
		cout<<"0.00%\n";continue;
	}
	if(n>=7)
	{
		cout<<"36.79%\n";continue;
	}
	for(i=4;i<=n;i++)
	{
		a[i]=i*a[i-1];
		b[i]=(b[i-1]+b[i-2])*(i-1);
	//	printf("%lf\n",a[i]);
	}
	
	
	double tmp=b[n]/a[n]*100;
	printf("%.2lf%%\n",tmp);

	}
	
	
	return 0;
}
