#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int a[200]={0};



int main()
{
	int s,i,j,k,n;
	cin>>s>>n;
	j=n;
	for(i=1;i<=n+1;i++)
	{	
		
		int tmp=j*s;
		j--;
		k=i;
		while(1)
		{	
			if(tmp==0)
			{
				break;
			}
			a[k]+=(tmp%10);
			if(a[k]>=10)
			{
				a[k+1]+=(a[k]/10);
				a[k]=a[k]%10;
				
				//cout<<"a[3]="<<a[3]<<endl;
			}
			tmp/=10;
			k++;
		}
	
		if(a[i]>=10)
		{a[i+1]+=(a[i]/10);
			a[i]=a[i]%10;
			
		}
		
		
		
//		for(int u=n+1;u>=1;u--)
//	{
//		
//		cout<<a[u]<<" ";
//	}
//	
//	cout<<"  "<<a[2]<<endl;	
	}
	for(i=n+1;i>=1;i--)
	{
		if(i==n+1)
		{
			if(a[i]!=0)
			{
				cout<<a[i];
			
			}
			else
			{
				continue;
			}
		}
		cout<<a[i];
	}
	
	return 0;
}


