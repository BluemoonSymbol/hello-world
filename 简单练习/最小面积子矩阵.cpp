#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

	
int b[100][100];	

int main()
{

	int n,m,i,j,k,l,s,sum=0,min=-1,x,y;
	cin>>n>>m>>s;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>b[i][j];
		}
		
	}
	
	
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=m;j++)
		{
			for(k=i;k<=n;k++)
			{
				
				for(l=j;l<=m;l++)
				{
					
					for(x=i;x<=k;x++)
					{
						for(y=j;y<=l;y++)
						{
							sum+=b[i][j];
							if(sum>=s)
							{
								min=(k-i+1)*(l-j+1);
								goto cc;
							}
						}
					}
					
					cc:{};
					sum=0;
					
				}
				
			}
			
			
		}	
		
	}	
	
	cout<<min;
	return 0;
}


