#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<windows.h>

using namespace std;

int main()
{
	int a[6]={10,6,2,5,3,1};
	
	sort(a+1,a+5);
	for(int i=0;i<6;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
