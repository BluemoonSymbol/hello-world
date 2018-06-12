#include<cstdio>
#include<iostream>
using namespace std;
#define  LL  long long

unsigned LL a[50]={0};

//LL ft(int n)
//{
//	if(n==1||n==2||n==3)return 1;
//	return ft(n-1)*2+3*ft(n-2)+5*ft(n-3);
//}

int main()
{

	int n;
	while(~scanf("%d",&n))
	{
		int i,j,k;
		a[1]=1;a[2]=1;a[3]=1;
		if(n<=3)
		{
			cout<<1<<endl;
			continue;
		}
		
		for(i=4;i<=n;i++)
		{
			a[i]=a[i-1]*2+a[i-2]*3+a[i-3]*5;
		}
		cout<<a[n]<<endl;
		
		
		
		
	}
	
	return 0;
}
