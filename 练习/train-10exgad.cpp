#include<cstdio>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>  
#include <map> 

#define LL long long  
 
using namespace std; 
int c=1;
LL Exgcd(int a,int b,int &x,int &y)
{
     if(b==0)
     {
         x=1, y=0;
         return a;
     }
     int r=Exgcd(b,a%b,x,y);
     int tp=x;
     x=y;
     y=tp-a/b*y;
     return r;
 }
 
 void small(int a,int b,int d,int &x,int &y)
{
    a /= d;
	b/= d;
	c/= d;
    x*=c; 
    y*=c;
     int tmp = x;
     x%=b;
     if(x<=0)
	{
	 	 x+=(int)abs(b*1.0);
	}
     int k=(tmp-x)/b;
     y += k*a;
     printf("%d %d\n",x,y);
 }
 
 int main()
 {
     int a,b,d,x,y;
     while(~scanf("%d%d",&a,&b))
     {
     	
        d=Exgcd(a,b,x,y);
         if(a==0&&b==0&&c==0)
		 {
		 	cout<<"1 -1"<<endl;
		 	continue;
		  } 
         if((a==0&&b==0&&c)||c%d||(a&&b==0&&c==0))
         {
         	cout<<"sorry"<<endl;
         	continue;
		 }
             
         if(a&&b==0)
         {
         	cout<<c/a<<" "<<-c/a<<endl;continue;
		 }
             
         if(a==0&&b)
         {
         	 cout<<"1"<<" "<<c/b<<endl;continue;
		 }
            
         small(a,b,d,x,y);
             
     }
    return 0;
 }
