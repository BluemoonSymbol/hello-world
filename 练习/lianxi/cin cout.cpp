#include<iostream>
#include<windows.h>
#include<cstdio>
using namespace std;

int main()
{	

	system("color 4b");
	int i;
	int &hh=i;
	char c;
	double f;
	cin>>i>>c>>f;
	hh++;
	cout<<"i="<<i<<'\t'<<"c="<<(int)c<<'\t'<<"f="<<f;
	int *p=&i;
	//char *pa="hello world";
	//cout<<i<<'\t'<<c<<'\t'<<pa<<endl;
	
	
	return 0;
}
