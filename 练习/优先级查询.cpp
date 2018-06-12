#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std; 

typedef struct
{
	double rank;
	int u,v,l,t,w,c,f;	
}road;
  
road a[1000002];  
int cmp(const road &a,const road &b)
{
    if(a.l<b.l)
    {
    	return 1;
	}
	else
	{
		if(a.l==b.l)
		{
			if(a.t<b.t)
			{
				return 1;
			}
			
			else
			{
				if(a.t==b.t)
				{
					if(a.w<b.w)
					{
						
						return 1;
					}
					
					else
					{
						if(a.w==b.w)
						{
							if(a.c<b.c)
							{
								return 1;
								
							}
							
							else
							{
								if(a.c==b.c)
								{
									if(a.f<b.f)
									{
										return 1;
										
									}

								}
								
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		
	}
	return 0;
	
}  
int main()
{
	int n,i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].l>>a[i].t>>a[i].w>>a[i].c>>a[i].f;
	//	a[i].rank=a[i].f*0.0001+a[i].c*1+a[i].w*1000+a[i].t*1000000+a[i].l*100000000;
	}
	sort(a+1,a+n+1,cmp);
	
//	cout<<a[b].u<<" "<<a[b].v<<" "<<a[b].l<<" "<<a[b].t<<" "<<a[b].w<<" "<<a[b].c<<" "<<a[b].f<<endl;
	
	
	int m;
	cin>>m;
	while(m--)
	{
		int b;
		cin>>b;
		cout<<a[b].u<<" "<<a[b].v<<" "<<a[b].l<<" "<<a[b].t<<" "<<a[b].w<<" "<<a[b].c<<" "<<a[b].f<<endl;
		
	}

	
	
	
	return 0;


}  
  
  
  
