#include<cstdio>  
#include<algorithm>  
#include<cmath>  
#include<cstring>  
#include<iostream>  
using namespace std;  
const int L=100005,inf=1<<30,maxn=1005;  
struct node{int s,y,w;}edge[L];  
int Fa[maxn],n,m,id[maxn],idPos;  
void init();  
int Find(int x);  
void unite(int x,int y);  
bool cmp(node a,node b);  
bool same(int x,int y);  
int kruskal();  
int secondTree(int pos)  
{  
    init();  
  
    int sum=0,cnt=0;  
    for(int i=0;i<m;i++)  
    {  
        if(cnt==n-1) break;  
        if(i==pos) continue;  
        if(!same(edge[i].s,edge[i].y))  
        {  
            unite(edge[i].s,edge[i].y);  
            sum+=edge[i].w;  
            cnt++;  
        }  
    }  
    if(cnt!=n-1) return -1;  
    return sum;  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        int Min=inf;idPos=0;  
        scanf("%d%d",&n,&m);  
        for(int i=0;i<m;i++)
        {
        	scanf("%d%d%d",&edge[i].s,&edge[i].y,&edge[i].w); 
		}
  int mst=kruskal();  
        if(mst==-1) {printf("-1\n");continue;}  
      
        for(int i=1;i<=idPos;i++)  
        {  
            int secmst=secondTree(id[i]);  
            if(secmst!=-1) Min=min(Min,secmst);  
        }  
        if(Min!=inf) printf("%d\n",Min);  
        else printf("-1\n");  
    }  
    return 0;  
}  
void init()
{  
    for(int i=0;i<=n;i++) Fa[i]=i;  
}  
int Find(int x)
{  
    if(Fa[x]==x) return x;  
    else return Fa[x]=Find(Fa[x]);  
}  
void unite(int x,int y)
{  
    x=Find(x);y=Find(y);  
    if(x==y) return ;  
    Fa[y]=x;  
}  
bool same(int x,int y)
{  
    return Find(x)==Find(y);  
}  
bool cmp(node a,node b)  
{  
    return a.w<b.w;  
}  
int kruskal()  
{  
    init();  
    sort(edge,edge+m,cmp);  
    int sum=0,cnt=0;  
    for(int i=0;i<m;i++)  
    {  
        if(cnt==n-1) break;  
        if(!same(edge[i].s,edge[i].y))  
        {  
            unite(edge[i].s,edge[i].y);  
            sum+=edge[i].w;  
            cnt++;  
            id[++idPos]=i;  
        }  
    }  
    if(cnt!=n-1) return -1;  
    return sum;  
}  

