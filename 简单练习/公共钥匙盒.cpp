#include<cstdio>  
#include<iostream>  
#include<cstring>  
#include<algorithm>  
#include<queue>  
#include<map>  
#include<vector>  
#include<iterator>  
#include<set>  
#include<cmath>  
#include<stack>  
#include <fstream>  
#define ll int  

using namespace std;  
const int maxn = 1005;  
int flag[maxn];

  
struct node
{  
    int w,s,e;  
}N[maxn],E[maxn]; 

 
bool cmp1(node a,node b)
{  
    if(a.s==b.s)  
        return a.w<b.w;  
    return a.s<b.s ;  
}  


bool cmp2(node a,node b)
{  
    if(a.e == b.e)  
        return a.w < b.w;  
    return a.e < b.e ;  
}  
int main()
{  
    int n,k,i,j;  
   cin>>n>>k;
	  
        for(i=0;i<k;i++)
		{  
            cin>>N[i].w>>N[i].s>>N[i].e; 
			 
            N[i].e+= N[i].s; 
			 
            E[i] = N[i];  
        }  
        for(i=0;i<maxn;i++) 
		{
				flag[i] = i; 	
		}
		 
        sort(N,N+k,cmp1); 
		
		 int yy[4]={6,7,5,8};
		 sort(yy,yy+4);
        sort(E,E+k,cmp2);  

        int f1=0,f2=0;
        
        
        while(f1<k)
		{  
                for(i=1;i<=n;i++)
				{  
                    if(flag[i]==N[f1].w)
					{  
                        flag[i]=-1;  
                        break;  
                    }  
                }  
            f1++;  
            while(E[f2].e<=N[f1].s)
			{  
                for(i=1;i<=n;i++)  
                    if(flag[i]==-1)
					{  
                        flag[i]=E[f2].w;  
                        break;  
                    }  
                f2 ++;  
            }  
        }  
        for(f2;f2<k;f2++)
		{  
            for(i=1;i<=n;i++)
			{  
                if(flag[i]==-1)
				{  
                    flag[i]=E[f2].w;  
                    break ;  
                }  
            }  
        }  
       cout<<flag[1];  
        for(int i=2;i<=n;i++)
		{
			cout<<" "<<flag[i];  
		  }  
            
         
      
    return 0;  
}  
