#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

char aa[100005]={0},a[100005]={0};

int main()
{
	scanf("%s",aa);
	
	int i,j,k,m;
	
	
	scanf("%d",&m);
	while(m--)
	{
		for(i=0;i<strlen(aa);i++)
		{
			a[i]=aa[i];
		}
		int u,v,count=0;
		scanf("%d%d",&u,&v);
		char b[10000]={0},c[100000]={0};
		int n=strlen(a);
		for(i=0;i<n;i++)
		{
		
			if(a[i]=='P')
			{
				count++;
				
				if(count==u)
				{
					int cnt=0;
					for(k=0;k<i;k++)
					{
						if(a[k]!='P'&&a[k]!='B'&&a[k]!='0')
						{
							b[cnt]=a[k];
							cnt++;
						}
						
					}
				}
				
				if(count==v)
				{
					int cnt=0;
					for(k=0;k<i;k++)
					{
						if(a[k]!='P'&&a[k]!='B'&&a[k]!='0')
						{
							c[cnt]=a[k];
							cnt++;
						}
						
					}
				}
				
				if(count>=max(u,v))
				{
					break;
				}
				
			}
			if(a[i]=='B')
			{
				for(j=i;j>=0;j--)
				{
					if(a[j]!='P'&&a[j]!='B'&&a[j]!='0')
					{
						a[j]='0';
						break;
					}
				}
				
				
			}
			
			
		}

		int t1=strlen(b),t2=strlen(c);
	/*	
		for(i=0;i<=strlen(b);i++)
		{
			cout<<b[i];
		}
		cout<<endl;
		for(i=0;i<=strlen(c);i++)
		{
			cout<<c[i];
		}
		cout<<endl;
	*/	
		if(strlen(b)>strlen(c))
		{
			printf("0\n");
			continue;
		}
		
		int counter = 0;
		char *temp;
		
		temp=c;
		while(temp)
	   {
	      temp=strstr(temp,b); 
	      if(temp!=NULL) 
	      {
	         temp+=strlen(b);
	         counter++;
	      }
	 
	   }
	 
	   printf("%d\n", counter);
		
		
	}
	
	
	
	
	
	return 0;
}
