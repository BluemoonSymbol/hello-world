#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std; 
long long tpp=0;


long long int pan(long long int k)
{
	long long a,b,biaoji=100;
	a=30;b=2*a;
	while(1)
	{
		if(a<=k&&k<=b)
		{
			tpp=a;
			return biaoji;
			break;	
		}
		a*=6;
		biaoji*=10;
		b*=6;	
	}
}



bool ju(long long int n)
{
	int i,tmp=1;
	while(1)
	{
		if(n==0)
		{
			break;
		}
		tmp=n%10;
		if(tmp==2||tmp==3||tmp==5||tmp==7)
		{
			return 0;
		}
		n/=10;
	}
	
	return 1;
	
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		
		tpp=0;
		unsigned long long  k,i=0,count=0; 
		scanf("%lld",&k);
		if(k<=30)
		{
			goto u;
		}
		 i=pan(k);

			count=tpp;
			printf("i=%d\n",i);
			printf("count=%d\n",count);
			printf("k=%d\n",k);
		
		u:{};
			while(1)
			{	
				if(count==k)
				{	i--;
					printf("%lld\n",i);
					break;
				}
				
				if(ju(i)==1)
				{
					count++;
				}
				i++;
				
			}		
		}
		
	return 0;
	
 } 
		

	

