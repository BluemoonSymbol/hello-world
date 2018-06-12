
5 5
1 3 2 0 3
1 0 2 3 3

//两个数组的最长公共子列 

 
#include<bits/stdc++.h>  
using namespace std;  
int f[10001][10001];  
int s[10001],t[10001];  
int MAX(int x,int y)  
{  
    if(x>y) return x;  
    return y;  
}  
int main()  
{  
    int lens,lent,i,j;  
    scanf("%d%d",&lens,&lent);  
    for(i=1; i<=lens; i++)  
        scanf("%d",&s[i]);  
    for(j=1; j<=lent; j++)  
        scanf("%d",&t[j]);  
    for(i=0; i<=lens; i++)  
        f[i][0]=0;  
    for(j=0; j<=lent; j++)  
        f[0][j]=0;  
    for(i=1; i<=lens; i++)  
    {  
        for(j=1; j<=lent; j++)  
        {  
            if(s[i]==t[j])  
            {  
                f[i][j]=f[i-1][j-1]+1;  
            }  
            else  
            {  
                f[i][j]=MAX(f[i-1][j],MAX(f[i][j-1],f[i-1][j-1]));  
            }  
        }  
    }  
    printf("%d\n",f[lens][lent]);  
    return 0;  
}  
