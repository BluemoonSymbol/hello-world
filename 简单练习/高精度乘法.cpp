#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
    char a1[250], b1[250];  
    int a[250], b[250], c[500] = {0};  
    int len1, len2, len;  
    scanf("%s%s",a1,b1);  
    len1 = strlen(a1);  
    len2 = strlen(b1);  
    len = len1+len2; 
    for (int i=0;i<len1;i++)
	{
		a[i] = a1[len1-1-i]-48;
	}   
        
   
    for (int j=0;j<len2;j++)
    {
    	 b[j] = b1[len1-1-j]-48;
	}
       
    for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++) 
		{ 
            c[i+j]+=a[i]*b[j];  
            c[i+j+1]+=(c[i+j])/10; 
            c[i+j]=c[i+j] % 10;  
        }  
	}  
        
    if (c[len-1] == 0)
	{
		len--;
	 } 
        
    for (int i = len-1; i >= 0; i--)
	{
		 cout<<c[i];
	 } 
       
   

	
	
	return 0;
}

