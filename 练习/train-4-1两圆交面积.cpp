#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
using namespace std;  

#define long long ll;  
const double PI = 3.1415926;  

struct ball
{  
    double x, y;  
    double r;  
} c[2];  

double dis(ball a, ball b) 
{  
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));  
}  

double solve(ball a, ball b)
 {  
    double d = dis(a, b);  
    if(d>= a.r + b.r)
	{
		return 0;
	 } 
          
    if (d <= fabs(a.r - b.r)) 
	{  
        double r;
		if(a.r < b.r)
		{
			r=a.r ;
		}
		 else
		 {
		 	r=b.r;
		 }
        return PI * r * r;  
    }  
    
    double ang1 = acos((a.r * a.r + d * d - b.r * b.r) / 2. / a.r / d);  
    double ang2 = acos((b.r * b.r + d * d - a.r * a.r) / 2. / b.r / d);  
    double ret = ang1 * a.r * a.r + ang2 * b.r * b.r - d * a.r * sin(ang1);  
    return ret;  
}  

int main() 
	{  
		double l=c[0].r+c[1].r+dis(c[0],c[1]);
		double s=sqrt(l*(l-c[0].r)*(l-c[1].r)*(l-dis(c[0],c[1])));
    	scanf("%lf%lf%lf%lf%lf%lf", &c[0].x, &c[0].y, &c[0].r, &c[1].x, &c[1].y, &c[1].r);
	  
        printf("%.3f\n", solve(c[0], c[1]));  
         return 0;
    } 
     

