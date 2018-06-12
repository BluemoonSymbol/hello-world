#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int price[1001]={0},size[1001]={0};
int d[1001][1001]={0};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,i,j,k;
		cin>>n>>m;
		for(i=1;i<=n;i++)
		{
			cin>>price[i];
		}
		for(i=1;i<=n;i++)
		{
			cin>>size[i];
			
		}
		for(int i=1;i<=n;i++)  
        {  
            for(int j=0;j<=m;j++)  
            {  
                if(j>=size[i])
				{
					if(d[i-1][j]>(d[i-1][j-size[i]]+price[i]))
					{
						d[i][j]=d[i-1][j];
					}
					else
					{
						d[i][j]=d[i-1][j-size[i]]+price[i];  
					}
				  }  
                    
                else
				{
					d[i][j]=d[i-1][j];  
				  }  
                    
            }  
  
        }  
        cout<<d[n][m]<<endl;  
    }  
   
	return 0;
}
