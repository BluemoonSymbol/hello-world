#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n,i;
	int a;
	while(cin>>a>>n)
	{
		long long int sum=a,temp=a;
		for(i=1;i<n;i++)
		{
			temp=10*temp+a;
			sum+=temp;
		}
		if(n==1)sum=a;
		cout<<sum<<endl;
	}
	
	
	return 0;
}

