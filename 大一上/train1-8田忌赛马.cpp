#include<stdio.h>  
#include<iostream>  
#include<cmath>
#include<cstring>
#include<algorithm>  

using namespace std;  
int a[3000],b[3000]; 
 
int cmp(int a,int b)  
{  
  return a>b;      
}  

int main()  
{  


 int bb[3]={0,9,8};
 sort(bb,bb+3);
   int i,n,j,sum,k,f,ji;  
   while( 1 )  
   {  
   
      cin>>n;
      if(n==0)
      {
      	break;
	  }
      for(i=0;i<n;i++)  
      {
      	 scanf("%d",&a[i]);
	  }
           
      for(i=0;i<n;i++)  
	  {
	  	cin>>b[i];  
    }      
        
	    sort(a,a+n,cmp);     
        sort(b,b+n,cmp);  
      ji=0;    
      i=j=sum=0;  
      k=n-1;  
      f=n-1;  
     while(1)  
     {             
         if(ji==n) 
		 {
		 	 break; 
		 }  
         if(b[j]>a[i])
		  {  
		   sum-=200;j++;k--;ji++; 
		   continue;
		  }  
         if(b[j]==a[i])
		 {                                     
                  if(b[f]<a[k])
			   {
					f--;
				  	k--;
			   		sum+=200;
					ji++;
				   continue;
			   } 
                  if(b[j]>a[k])
			   {
				   sum-=200;
				   k--;
				   j++;
				   ji++;
			   }  
                   else 
				{
				   k--;
				   j++;
				   ji++;
				}  
                continue;  
            }  
          if(b[j]<a[i])
		  {
			  sum+=200;
			  j++;
			  i++;
			  ji++;
			  continue;
		  }  
     }            
     cout<<sum<<endl;      
  }  
}  

