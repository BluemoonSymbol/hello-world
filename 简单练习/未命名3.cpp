#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;


int main()
{
	char a[1000];
	char b[1000];
	char c[1000]={0};
	scanf("%s%s",a,b);
	int l1=strlen(a),l2=strlen(b);
	int i,j=l2-1,k=0;

	for(i=l1-1;i>=0;i--)
	{
		
		if(a[i]!=b[j]||j<0)
		{
		//	cout<<"ddd"<<endl;
			break;
		}
		if(a[i]==b[j])
		{
			
			//cout<<"hhh"<<endl;
			c[k]=a[i];
			k++;
			j--;
		}
		
		
	}
	if(c[0]==0)
	{
		cout<<"null";
	}
	for(i=strlen(c)-1;i>=0;i--)
	{
		cout<<c[i];	
	}
	
	return 0;
}


