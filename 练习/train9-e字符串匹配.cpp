#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
char a[1000];
char b[1000];
using namespace std; 
int main()
{
	while(1)
	{
		
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
    	char *p = a;
    	int count = 0;
    
    	scanf("%s",a);
    	if(a[0]=='#')
    	{
    		break;
		}
   
    	scanf("%s",b);
    	int m=strlen(b);
   	 while((p = strstr(p,b)) != NULL)
   	 {
       	 count ++;
      	 p+=m;
   	 }
 
    	printf("%d\n",count);
	}
    
return 0;
 
}
