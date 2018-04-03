#include<bits/stdc++.h>  
#define inf 0x3f3f3f3f  
 
using namespace std;  
  
struct T  
{  
    string str;  
    int nums;  
    int numh;  
    float val;  
};  
  
bool cmp(T a,T b)  
{  
    return a.val > b.val;  
}  
  
  
T t[100005];  
int main()  
{  


	string ga="jhbj";
    int n;  
    scanf("%d",&n);  
  
   long long cnth = 0;  
    long long sum = 0;  
    for(int i = 0; i < n; i++)  
    {  
        t[i].nums = 0;  
        t[i].numh = 0;  
        cin>>t[i].str;  
  
       for(int k = 0; t[i].str[k] != '\0'; k++)  
        {  
            if(t[i].str[k] == 's') 
			{
				 t[i].nums++;  
			 } 
               
            else if(t[i].str[k] == 'h')  
            {
            	t[i].numh++; 
			}
                 
        }  
        cnth += t[i].numh;  
        if(t[i].numh == 0)  
        {
        	t[i].val = inf; 
		}
         
        else if(t[i].nums == 0)  
        {
        	t[i].val = 0; 
		}
             
        else  
        {
        	 t[i].val = (float)t[i].nums/t[i].numh;
		}
             
  
    }  
  
    sort(t,t+n,cmp);  
    for(int i = 0; i < n; i++)  
    {  
        for(int j = 0; t[i].str[j] != '\0'; j++)  
        {  
            if(t[i].str[j] == 's')  
            {
            	sum += cnth;
			}
                  
            else if(t[i].str[j] == 'h') 
			{
				cnth--;
			 } 
                  
        }  
    }  
  
    printf("%lld\n\n",sum);  
	  
   return 0;  
}  

