#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

char a[100001];
int b[100001];
void find(int len)
{
	int i=0,j=-1;
	b[0]=-1;
	while(i!=len) 
	{
		if(j==-1 || a[i]==a[j])
		{
			i++;
			j++;
			b[i]=j;
		}
			
		else
		{
			j=b[j];
		}
			
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--) 
	{
		scanf("%s",a);
		int m=strlen(a);
		find(m);
		int n=m-b[m];
		if(n!=m&&m%n==0)
		{
			cout<<0<<endl;
		}
		
		else 
		{
		int tt=n-b[m]%n;
			cout<<tt<<endl;
		}
	}
	return 0;
}
