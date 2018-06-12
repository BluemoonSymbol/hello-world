#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <algorithm> 
#include <string> 
using namespace std; 



int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int i,j=1,k; 
		char a[1000];
		int b[100]={0};
		cin>>a;
	//	cout<<a<<endl;
		int m=strlen(a);
		for(i=0;i<m;i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			{
				b[j]*=10;
				b[j]+=a[i]-'0';
				if(a[i+1]==',')
				{
					j++;
				}
			}
			
		}
		
		int ans=0;
		for(i=1;i<=100;i++)
		{
			if(b[i]==0)
			{
				ans=i;
				break;
			}
		}
		
		sort(b+1,b+ans);
		
	//	cout<<"ans="<<ans<<endl;
		
		
//		for(i=1;i<ans;i++)
//		{
//			cout<<b[i]<<" ";
//		}
//		cout<<endl;
		
		int tp=0;
		//cout<<"maxn="<<b[ans-1]<<endl;
		for(i=b[ans-1]/2+1;i>=1;i--)
		{
			tp=0;
			for(k=1;k<ans;k++)
			{
				if(b[k]%i==0)
				{
					tp++;
				}
				if(tp==ans-1)
				{
					cout<<i<<endl;
					goto pp;
				}	
			}
		}
	pp:{};
	}
	return 0;
	
}
