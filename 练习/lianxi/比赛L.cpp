#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int la[100]={0},ba[100]={0};
int dp1[100][1000]={0},dp2[100][1000]={0};

int main()
{
while(1)
{
	int m,n;int i,j,k,sum1=0,sum2=0;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&la[i]);
		sum1+=la[i];
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&ba[i]);
		sum2+=ba[i];
	}
	
}
 
for(i=0;i<=sum1;i++)
{
	dp1[1][i]=1;
	dp1[0][i]=0;
	dp1[i][sum1]=i;
}

for(int i=1;i<=m;i++)  
    {  
        for(int j=1;j<=sum1;j++)  
        {  
            if(j>=la[i])
			{
				dp1[i][j]=max(dp1[i-1][j],dp1[i-1][j-la[i]]-1); 
			}  
                 
            else  
                dp1[i][j]=dp1[i-1][j];  
        }  
    } 
    
 for(i=0;i<=sum2;i++)
{
	dp2[1][i]=1;
	dp2[0][i]=0;
	dp2[i][sum2]=i;

}   
    
 for(int i=1;i<=n;i++)  
    {  
        for(int j=1;j<=sum2;j++)  
        {  
            if(j>=ba[i])
			{
				dp2[i][j]=max(dp2[i-1][j],dp2[i-1][j-ba[i]]-1); 
			}  
                 
            else  
                dp2[i][j]=dp2[i-1][j];  
        }  
    }    
    j=1;
    for(i=1;i<=sum1;i++)
    {
    	
    	j=i;
    		
    		
    		
		
    	
    	
	}

    
    
    
    
    return 0;
    
}


	 
