#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector> 
using namespace std;
typedef struct
{
	double x,y;
}P; 
int main()
{
	int t;
	cin>>t;
	P p1,p2,p3;
	while(t--)
	{
		cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y;
		double a = ( p2.y - p1.y ) / ( ( p2.x - p1.x ) * ( p2.x-p1.x ) );
		double b,c,q;	
		b=a*(-2)*p1.x;
		c=a*(p1.x)*(p1.x)+p1.y;
		double k=(p3.y-p2.y)/(p3.x-p2.x);
		q=p2.y-k*p2.x;
		double s1=a/3*p3.x*p3.x*p3.x+b/2*p3.x*p3.x+c*p3.x-k/2*p3.x*p3.x-q*p3.x,s2=a/3*p2.x*p2.x*p2.x+b/2*p2.x*p2.x+c*p2.x-k/2*p2.x*p2.x-q*p2.x;
	double s3=s1-s2;
	
	//cout<<"a="<<a<<endl<<"b="<<b<<endl<<"c="<<c<<endl<<"k="<<k<<endl;
	
	
	printf("%.2lf\n",s3);
	}

	return 0;
}


