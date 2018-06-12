#include<cstdio>  
const int N=50001;  
int p[N],r[N],n;  
int findset(int x)  
{  
    if(x!=p[x])  
    {  
        int fx=findset(p[x]);  
        r[x]=(r[x]+r[p[x]])%3;  
        p[x]=fx;  
    }  
    return p[x];  
}  
bool Union(int d,int x,int y)  
{  
    int fx=findset(x),fy=findset(y);  
    if(fx==fy)  
    {  
        if((r[y]-r[x]+3)%3!=d)return 1;  
        else return 0;  
    }  
    p[fy]=fx;  
    r[fy]=(r[x]-r[y]+d+3)%3;  
    return 0;  
}  
int main()  
{  
    int k,ans,i,d,x,y;  
    scanf("%d%d",&n,&k);  
    ans=0;  
    for(i=1;i<=n;i++)p[i]=i,r[i]=0;  
    while(k--)  
    {  
        scanf("%d%d%d",&d,&x,&y);  
        if(x>n||y>n||(x==y&&d==2))
		{
			ans++;
			continue;
		}  
        if(Union(d-1,x,y))
		{
			ans++; 	
		} 
    }  
    printf("%d\n",ans);  
    return 0;  
}
