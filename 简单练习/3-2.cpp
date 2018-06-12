#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#define  ll  long long int
using namespace std;


int main()
{
	int n,i=0,j=0,k=0;
	cin>>n;
	while(n--)
	{	k=0;
		char tmp[100];
		int m;
		char a[20];
		memset(a,0,sizeof(a));
		cin>>m;
		sprintf(a,"%d",m);//ÕûÊý´æÈë×Ö·û´® 
		int s=strlen(a);
		int ten=0;
		for(i=s-1;i>=0;i--)
		{
			ten+=(a[i]-'0')*pow(9,j);
			j++;
		}
		j=0;
		
		memset(tmp,0,sizeof(tmp));

		while(1)
		{
			if(!ten)
			{
				break;
			}
			
			tmp[k]=ten%2+48;
			k++;
			ten/=2;
	
		}
		int y=strlen(tmp);
	
	
		
		for(i=y-1;i>=0;i--)
		{
		
			cout<<tmp[i];
		}
		cout<<endl;	
	}
	return 0;
}
