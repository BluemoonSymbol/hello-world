#include<cstdio>  
#include<cmath>  
#define LL __int64  
LL POW(LL x , int z)  
{  
    LL ans = 1;  
    for(int i = 1 ; i <= z ;i++)  
    {  
        ans*=x;  
    }  
    return ans;  
}  
int main()  
{  
    LL x,y,tx,ty,ans;  
    int z,k;  
    while(~scanf("%d",&k) && k)  
    {  
        ans = 0;  
        LL tmp = (int)sqrt(k*1.0);  
        if(tmp *tmp == k)
        {
        	ans+=(tmp-1)/2; 
		}
             
        for( z = 3 ; z < 31 ; z++) 
        {  
            for(LL x = 1 ; ; x++)  
            {  
                tx = POW(x,z);  
                if(tx >= k/2)  
                    break;  
                for(LL y = x+1; ; y++)  
                {  
                    ty = POW(y,z);  
                    if(tx+ty+x*y*z > k)  
                        break;  
                    else if(tx+ty+x*y*z == k)  
                    {  
                        ans++;  
                        break;  
                    }  
                }  
            }  
        }  
        printf("%I64d\n",ans);  
    }  
    return 0;  
}  
