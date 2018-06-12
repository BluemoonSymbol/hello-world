#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
using namespace std; 


int main()
{
	char s[1000],t[1000];
	cin>>s>>t;
	int m1=strlen(s),m2=strlen(t);
	if(m2>m1)
	{
		cout<<"NO";
	}
	else
	{
		
		int i,j,count=0,tmp=0;
		for(i=0;i<m2;i++)
		{
			for(j=tmp;j<m1;j++)
			{
				
				if(t[i]==s[j])
				{
					count++;
					tmp=j;
					break;
					
				}		
			}
			
		}
		
		
		if(count==m2)
		{
			cout<<"YES";
		}
		else
		{
			cout<<"NO";
		}
		
		
		
	}
	
	return 0;
	
}
