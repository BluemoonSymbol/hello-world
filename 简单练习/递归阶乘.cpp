#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{int count=0;
	
		
		int n;
	cin>>n;
	
	int i,j=1,k,a=0,b=0,c=0,d=1;

	for(i=1;i<n;i++)
	{	
		d=d+c;
		c=b;
		b=a;
		a=d;
	}
	int sum=a+b+c+d;
	cout<<sum<<endl;
	 
	
	
	return 0;
}
