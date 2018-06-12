#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int a[100]={1,3,5,7};

int main()
{
	
	cin>>a[4];
	sort(a,a+5);
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
	
	return 0;
}

