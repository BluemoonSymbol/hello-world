#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define   LL long long
int judge(LL  num)
{
	int i=1,j;
	int a[20]={0},tmp;
	while(1)
	{
		a[i]=num%10;
		i++;
		num/=10;
		if(num==0)
		{
			break;
		}
	}
	int y=1;
	for(j=i-1;j>=(i-1)/2-1;j--)
	{
		tmp=a[j];
		if(tmp!=a[y])
		{
			return 0;
			break;
		}
		y++;
			
	}	
	return 1;	
}
LL tran(LL num)
{	
	int i=1,j;
	int a[20]={0},tmp;
	while(1)
	{
		a[i]=num%10;
		i++;
		num/=10;
		if(num==0)
		{
			break;
		}
	}
	LL x=a[1];
	for(j=1;j<i-1;j++)
	{
		x=x*10+a[j+1];
	}	
	return x;
}
int main()
{
	LL n,sum=0;
	cin>>n;
	sum=n;
	while(1)
	{
		if(sum>2100000000)
		{
			cout<<"No";
			break;
		}
		if(judge(sum))
		{
			cout<<sum<<" ";
			break;
		}
		sum+=tran(sum);	
	}
	return 0;
}
