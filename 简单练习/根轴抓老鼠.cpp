#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

typedef struct 
{
	int x,y,z,r;
}P;


int main()
{
	P a,b,c;	
	int n,i,j,k;
	cin>>n;
	while(n--)
	{
		cin>>a.x>>a.y>>a.z>>a.r>>b.x>>b.y>>b.z>>b.r>>c.x>>c.y>>c.z;
		int d1=(c.x-a.x)*(c.x-a.x)+(c.y-a.y)*(c.y-a.y)+(c.z-a.z)*(c.z-a.z);
		int d2=(c.x-b.x)*(c.x-b.x)+(c.y-b.y)*(c.y-b.y)+(c.z-b.z)*(c.z-b.z);
		if(d1-a.r*a.r==d2-b.r*b.r)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
	}
	
	
	return 0;
}



