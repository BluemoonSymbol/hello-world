#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;


int count=1;
int sm(int x)
{
	int i,j;
	for(i=1;i<=(x+1)/2;i++)
	{
		if(x%i==0)
		{
			count++;
		}
		
		
	}
	if(x==1)count--;
	return count;
	
	
}




int a[10000];
int main()
{
	int n,i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
		
	for(i=1;i<=n;i++)
	{
		count=1;
		
		cout<<sm(a[i])<<endl;
	}	
		
		
		
		
	
	return 0;
}


