#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a=n%50,b=a/30,c=a%30;
	int sum=(n/50)*7+b*4+c/10;
	//cout<<a<<" "<<b<<" "<<c<<endl;
	cout<<sum;
	return 0;
 } 
 
 
