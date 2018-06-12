#include<stdio.h>  
int main()  
{  
    double  b[21]={0,0,1,2};  
    int i,j,n,m;  
    double a[21]={1,1,2,6};  
    for(i=4;i<=20;i++){  
        a[i]=i*a[i-1];  
        b[i]=(i-1)*(b[i-1]+b[i-2]);  
    }scanf("%d",&m);  
    while(m--){  
       scanf("%d",&n);  
       printf("%.2lf%%\n",b[n]/a[n]*100);  
    }  
  
    return 0;  
}  
