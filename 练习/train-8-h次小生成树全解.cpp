#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
#define MAX 105  
const int INF=0x3f3f3f3f;  
int g[MAX][MAX],dist[MAX],mmax[MAX][MAX];  ///g�����ͼ  dist�������㵽�������ľ��� maxn�����i��j������Ȩֵ  
int pre[MAX]; ///pre����j��������������ĸ���  
bool mark[MAX]; ///�൱��vis  ������Ǹõ��Ƿ��Ѿ��ù�  
bool connect[MAX][MAX]; ///����i-j���������Ƿ��������С������  false ���� true  û��  
int mst,mint; ///mst������С��������Ȩֵ��  
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
              fa=pre[p]; ///�ҵ���p����ĵ�  
              connect[fa][p]=false;  
              connect[p][fa]=false;  
              mmax[fa][p]=min;  
              ///�������еĵ� ������㵽p�����Ȩֵ  
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
                            ///���i-j�����߼�������С������ ����i-j����·��ͨ  continue  
                            if(connect[i][j]==false||g[i][j]==INF)  
                                   continue;  
                            ///�������ıߺ�ɾ���ıߵĴ�С��һ����  ˵����С��������Ȩֵ�͵�����С��������Ȩֵ��  
                            ///Ҳ����˵��С��������Ψһ  
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
