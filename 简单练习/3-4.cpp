#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
using namespace std; 

#define ll long long
ll fib(int n)
{
	if(n==1)
	{
		return 1;
	}
	if(n==2)
	{
		return 2;
	}
	return fib(n-1)+fib(n-2);
	
}
int main()
{
	int n;
	cin>>n;
	cout<<fib(n);
	
}



