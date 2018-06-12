#include <cstdio>
#include<iostream>
using namespace std;
int count = 0;
void hanio(int n, char a, char b, char c) 
{
	if (n == 1) 
	{
		printf("%c->%c\n", a, b);
		count++;
		return;
	}
	
	hanio(n - 1, a, c, b);
	printf("%c->%c\n", a, b);
	count++;
	hanio(n - 1, c, b, a);
}

int main() 
{
	int n;
	scanf("%d",&n);
	if(n==0)
	{
		cout<<"0";
		return 0;
	}
	hanio(n, 'A', 'C', 'B');
	printf("%d\n", count);
	return 0;
}
