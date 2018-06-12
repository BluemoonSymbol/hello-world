#include<stdio.h>
#include<string.h>
 int dp[101][101];      
 struct node
 {
     int e;     
     int r;     
 }a[101];
 
 int main()
 {
     int n,m,k,s,i,j,t;
     while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF)
    {
         for(i=1;i<=k;++i)
            scanf("%d%d",&a[i].e,&a[i].r);
         memset(dp,0,sizeof(dp));
         for(i=1;i<=k;++i)  
             for(j=a[i].r;j<=m;++j)  
                 for(t=1;t<=s;++t)   
                 {
                     if(dp[j][t]<dp[j-a[i].r][t-1]+a[i].e)
                     {
                         dp[j][t]=dp[j-a[i].r][t-1]+a[i].e;
                     }
                 }
        if(dp[m][s]>=n)     
         {
                 for(i=0;i<=m;++i)   
                     if(dp[i][s]>=n) 
                     {
                         printf("%d\n",m-i);
                        break;
                     }
         }
         else
         {
         	printf("-1\n");
		 }
             
     }
     return 0;
 }
 
 
/*
Sample Input  n m k s

10 10 1 10
1 1
10 10 1 9
1 1
9 10 2 10
1 1
2 2
Sample Output
0
-1
1

*/
