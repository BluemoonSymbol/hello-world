#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<windows.h>

int y=0;
using namespace std;

typedef struct 
{
	int x,y;
}pt;

typedef struct 
{
	pt l,r;
	int flag;
	int b;
	
} pg;

int main()
{
	int n,m,i,j,k;
	cin>>n>>m;
	pg a[n+1];
	
	for(i=1;i<=n;i++)
	{
		cin>>a[i].l.x>>a[i].l.y>>a[i].r.x>>a[i].r.y;
		a[i].flag=0;
		a[i].b=i;
	}
	
	pt c[n+1];
	for(i=1;i<=m;i++)
	{
		cin>>c[i].x>>c[i].y;
	}
	
	for(i=1;i<=m;i++)
	{	
		int count=n;
	
		int tmp[n]={0},cc=1;
			
			for(k=1;k<=n;k++)
			{
			
				if(c[i].x>=a[k].l.x&&c[i].x<=a[k].r.x&&c[i].y>=a[k].l.y&&c[i].x<=a[k].r.y)
				{
					a[k].flag=1;
					tmp[cc]=a[k].b;
					cc++;
					
				}
		
			}
			
			if(cc==1)
			{
				cout<<"IGNORED"<<endl;
				continue;
			}
			
			sort(tmp,tmp+cc-1);
			cout<<tmp[cc-1]<<endl;
			
		fuck: y+=1;
		
		
	}
	

	
	return 0;
}
