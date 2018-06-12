#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
#define MAX 105  
const int INF=0x3f3f3f3f;  
int g[MAX][MAX],dist[MAX],mmax[MAX][MAX];  ///g保存地图  dist保存从起点到其余各点的距离 maxn保存从i到j的最大边权值  
int pre[MAX]; ///pre保存j的离它最近的是哪个点  
bool mark[MAX]; ///相当于vis  用来标记该点是否已经用过  
bool connect[MAX][MAX]; ///保存i-j的那条边是否加入了最小生成树  false 加入 true  没有  
int mst,mint; ///mst保存最小生成树的权值和  
int n,m;  
int prim()  
{  
       int res=0,fa,p,min,i,j;  
       memset(mmax,0,sizeof(mmax));  
       for(i=1;i<=n;i++)  
       {  
              dist[i]=g[1][i];  
              pre[i]=1;  
              mark[i]=false;  
       }  
       dist[1]=0;  
       mark[1]=true;  
       for(i=1;i<n;i++)  
       {  
              p=-1;min=INF;  
              for(j=1;j<=n;j++)  
              {  
                     if(!mark[j]&&dist[j]<min)  
                     {  
                            p=j;  
                            min=dist[j];  
                     }  
              }  
              if(p==-1) return res;  
              mark[p]=true;  
              res+=dist[p];  
              fa=pre[p]; ///找到离p最近的点  
              connect[fa][p]=false;  
              connect[p][fa]=false;  
              mmax[fa][p]=min;  
              ///遍历所有的点 求其余点到p的最大权值  
              for(j=1;j<=n;j++)  
                     mmax[j][p]=(mmax[fa][p]>mmax[j][fa])?mmax[fa][p]:mmax[j][fa];  
              for(j=1;j<=n;j++)  
              {  
                     if(!mark[j]&&dist[j]>g[p][j])  
                     {  
                            dist[j]=g[p][j];  
                            pre[j]=p;  
                     }  
              }  
       }  
       return res;  
}  
  
int main()  
{  
       int tc;  
       scanf("%d",&tc);  
       while(tc--)  
       {  
              scanf("%d %d",&n,&m);  
              memset(g,INF,sizeof(g));  
              memset(connect,false,sizeof(connect));  
              while(m--)  
              {  
                     int u,v,c;  
                     scanf("%d %d %d",&u,&v,&c);  
                     g[u][v]=c;  
                     g[v][u]=c;  
                     connect[u][v]=true;  
                     connect[v][u]=true;  
              }  
              mst=prim();  
              int i,j;  
              bool flag=false;  
              for(i=1;i<=n;i++)  
                     for(j=1;j<=n;j++)  
                     {  
                            ///如果i-j这条边加入了最小生成树 或者i-j这条路不通  continue  
                            if(connect[i][j]==false||g[i][j]==INF)  
                                   continue;  
                            ///如果加入的边和删除的边的大小是一样的  说明次小生成树的权值和等于最小生成树的权值和  
                            ///也就是说最小生成树不唯一  
                            if(g[i][j]==mmax[i][j])  
                            {  
                                   flag=true;  
                                   break;  
                            }  
                     }  
              if(flag)  
                     printf("Not Unique!\n");  
              else  
                     printf("%d\n",mst);  
       }  
       return 0;  
}  
