#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int cal(int n)
{
	int i,ji=1;
	for(i=1;i<=n;i++)
	{
		
		ji*=i;
		while(1)
		{
			if(ji%10==0)
			{
				ji/=10;
			}
			else
			{
				break;
			}
		}
		
		ji=ji%10000;//magic number;
//		if(i>=n-10)
//		{
//			cout<<ji<<endl;
//		}
		
	}
	ji%=10;
	
	return ji;
	
	
}



int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int m;
		cin>>m;
		cout<<cal(m)<<endl;
	}	
	return 0;
}


