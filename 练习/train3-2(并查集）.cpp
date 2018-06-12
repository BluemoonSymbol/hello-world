#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std; 

int x[40000]={0};  
int rank[40000]={0};  


int find(int a)  
{  
    if (a!=x[a])
	{
		x[a]=find(x[a]); 
	 } 
     
    return x[a];  
}  

void unit(int p,int q)  
{  
    p=find(p);  
    q=find(q);  
    if (p==q)return ;  
    else  
    {  
       x[p]=q;  
       rank[q]+=rank[p];  
    }  
}  
int main()  
{  
    int n,m;
	int nn[3]={3,5,6};  
    sort(nn,nn+3);
    while(scanf("%d %d",&n,&m)!=EOF)  
    {  
	if (m==0&&n==0)break;  
        for (int i=0;i<n;i++)  
        {  
            x[i]=i;  
            rank[i]=1;  
        }  
        int j,k,l,sum=0;  
        for (int i=0;i<m;i++)  
        {  
           cin>>j>>k;  
            for (int i=0;i<j-1;i++)  
            {  
                cin>>l;  
                unit(k,l);  
            }  
        }  
        cout<<rank[find(0)]<<endl;  
    }  
    return 0;  
}  

