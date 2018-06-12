 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <queue>
#include <string>
 #include <vector>
 
using namespace std; 
 
int f[1000001],f1[1000001];
int find(int x)
{
	while(f[x]!=x)
	{
		x=f[x];
	}
	return x;
} 
 
void combine(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
	{
		f[x]=fy;
		f1[x]=f1[y];
	}	
	
	
} 
int main()
{
	int n,m,i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		f[i]=i;
		f1[i]=i;
	}	
	while(m--)
	{
		char tmp;int a,b;
		cin>>tmp>>a>>b;
	//	cout<<tmp<<" "<<a<<" "<<b<<endl;
		switch(tmp)
		{
			case 'Q':
				{
					
					if(f1[a]==f1[b])
					{
						cout<<'Y'<<endl;
					}
					else
					{
						cout<<'N'<<endl;
					}
					break;
				}
			
			case 'U':
				{
					
					f1[a]=find(a);
					f1[b]=find(b);
					combine(f1[a],f1[b]);
					break;
				}
			
			
		}
		

	
}
	return 0;
 } 
 
 
 
 
 
