#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n;
	while(cin>>n&&n)
	{
		int cnt=0;
		
		while(n!=1)
		{
			if(n%2==0)
			{
				n/=2;
			}	
				
			else
			{
				n=3*n+1;
				n/=2;
					
			}
			cnt++;
		}	
		
		cout<<cnt<<endl;
		
	}	
	
	
	return 0;
}

