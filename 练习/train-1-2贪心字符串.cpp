#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

char a[100005];
const char b[27]="abcdefghijklmnopqrstuvwxyz";

int main()
{	
	
	int count=0;
	int i=0,j,k;
	scanf("%s",a);
	
	
	
	int n=strlen(a);
	
//	cout<<"n="<<n<<endl;
	
	for(i=0;i<n;i++)
	{
		
		if(count==26)
		{
			break;
		}
	
		if(count>0)
		{
			if(a[i]<=b[count])
			{
				if(a[i]<=b[count])
				{
					a[i]=b[count];
					count++;
					
				}
			
				
			}
			
		}
		
		if(a[i]==b[count]&&count==0)
		{
			count++;
		}
		
	}
	
	if(count!=26)
	{
		cout<<"-1";
	}
	else
	{
		for(i=0;i<n;i++)
	{
		cout<<a[i];
	}
	}
	
	
	return 0;
}


