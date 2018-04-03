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
	while(1)
	{
		int i,k;
		double m;
		int n;
		cin>>m>>n;
		if(m==-1&&n==-1)
		{
			break;
		}
		
		shao a[n+1];
		
		for(i=1;i<=n;i++)
		{
			cin>>a[i].j>>a[i].f;
			a[i].D=a[i].f/a[i].j;
		}
		sort(a+1,a+n+1,cmp);
		
	
		
//	for(i=1;i<=n;i++)
//	{
//		cout<<a[i].D<<" "<<a[i].j<<" "<<a[i].f<<endl;
//	}
		
		double money=0;
		
		for(i=1;i<=n;i++)
		{
			
			
			
			if(m==0)
			{
				break;
			}
			if(m>=a[i].f)
			{
				m-=a[i].f;
				money+=a[i].j;
				continue;
			}
			
			if(m<a[i].f)
			{
				
				money+=m/a[i].D;
				m=0;
			}

		}
		
		printf("%.3lf\n",money);
		
	}
	
	
	
	
	return 0;
}





