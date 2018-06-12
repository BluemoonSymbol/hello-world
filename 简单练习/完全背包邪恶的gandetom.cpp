#include<algorithm>
#include<iostream>
#include <cstdio>  
#define N 50000  

using namespace std;

int f[N]={0},v[N],w[N];  

int main()  
{  
    int t,i,j,k,m,n,c;  
    
      
      
        scanf("%d%d",&c,&n);  
     
        //for(i = 0 ; i <= c ; i++)  
          //  f[i]=INF;  
        //scanf("%d",&n);  
        for(i=1;i<=n;i++)  
        {  
            scanf("%d%d",&v[i],&w[i]);
        }  
         
        for(i =1;i<=n;i++)  
        {  
            for(j = v[i] ; j <= c ; j++)  
            {  
                f[j] = max(f[j],f[j-v[i]]+v[i]*w[i]); 
            }  
        }  
         
            printf("%d\n",f[c]);  
      
    return 0;  
} 
