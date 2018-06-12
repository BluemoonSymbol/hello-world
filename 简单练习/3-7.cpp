#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	
	double n;
	cin>>n;
	if(n<=3500)
	{
		cout<<"0.00";
		return 0;
	}
	
	n-=3500;
	double r;
	if(n<=1500)
	{
		
		r=n*0.03;
		printf("%.2lf",r);
	 } 
	 if(n>1500&&n<=4500)
	 {
	 	r=45+0.1*n-150;
	 	printf("%.2lf",r);
	 }
	if(n>4500&&n<=9000)
	 {
	 	r=345+(n-4500)*0.2;printf("%.2lf",r);
	 }
	if(n>9000&&n<=35000)
	 {
	 	r=1245+(n-9000)*0.25;printf("%.2lf",r);
	 }
	 if(n>35000&&n<=55000)
	 {
	 	r=1245+26000*0.25+(n-35000)*0.3;printf("%.2lf",r);
	 }
	 if(n>55000&&n<=80000)
	 {
	 	r=1245+26000*0.25+6000+(n-55000)*0.35;printf("%.2lf",r);
	 }
	 if(n>80000)
	 {
	 	
	 	r=25000*0.35+1245+26000*0.25+6000+(n-80000)*0.45;printf("%.2lf",r);
	  } 
	return 0;
}



