#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	
	queue<int> c;
	int n;
	cin>>n;
	while(n--)
	{
		char a;
		cin>>a;
		if(a=='I')
		{
			int b;
			cin>>b;
			c.push(b);
		}
		if(a=='Q')
		{
			cout<<c.front();
			c.pop();
		}
		
		
	}
	
	
	return 0;
}



