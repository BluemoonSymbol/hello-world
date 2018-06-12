#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int getlast(int x)
{
	if(x%10==0) return 0;
	while(x>=10)
	{
		x = x%10;
	}
	return x;
}
int getjw(int x)
{
	int num = 0;
	while(x>=10)
	{
		x = x-10;
		num++;
	}
	return num;
}
int main()
{
	int b,n;
	//cout<<getlast(10*1+0)<<endl;
	while(cin>>b>>n)
	{
		int a[105];
		int jw = 0;
		for(int i=n;i>0;i--)
		{
			a[i] = getlast(i*b+jw);
			jw = getjw(i*b+jw);
		//	cout<<a[i]<<" "<<jw<<endl;
		}
		if(jw) cout<<jw;
		for(int i=1;i<=n;i++)
		{
			cout<<a[i];
		}
		cout<<endl;
	}
