#include <iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
	
using namespace std;
#define MAX(a,b) a>b?a:b
	
int main()
{
	int s[1001][31];
	int max=0,k,t,i,j,x,y;
	int a[1001];
	cin>>t>>k;
	for(i=1;i<=t;++i)
	cin>>a[i];
	for(i=0;i<=k;++i)
	s[0][i]=0; 
	for(i=1;i<=t;++i)
	{
	s[i][0]=s[i-1][0]+a[i]%2;
	for(j=1;j<=k;++j)
	{
	x=(j%2==(a[i]-1)?1:0);
	y=MAX(s[i-1][j-1],s[i-1][j]);
	s[i][j]=x+y;
	}
	}
	for(i=0;i<=k;++i)
	if(s[t][i]>max) max=s[t][i];
	cout<<max;
	return 0;
}
	

