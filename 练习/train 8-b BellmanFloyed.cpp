#include<stdio.h>  
#include<iostream>  
#include<string.h>  
    
using namespace std;    
    
#define inf 1e10    
    
int dis[1005];    
    
struct edge    
{    
    int s, e, t;    
}e[5200];    
    
int n, m, w_m;//number of nodes, number of edges_positive, number of edges_negative    
    
bool bellman(int countt)    
{    
    bool flag;    
        
    for(int i = 0; i < n-1;i++)    
    {    
        flag = false;    
        for(int j = 0; j < countt;j++)    
        {    
            if(dis[e[j].e] > dis[e[j].s] + e[j].t)    
            {    
                dis[e[j].e] = dis[e[j].s] + e[j].t;    
                flag = true;    
            }    
        }    
        if(!flag) break;    
    }    
    for(int i = 0; i < countt; i++)    
    {    
        if (dis[e[i].e] > dis[e[i].s] + e[i].t) {    
            return true;    
        }    
    }    
    return false;    
}    
    
    
int main()    
{    
    int N;    
    cin>>N;    
    while (N--) {    
        memset(dis, inf, sizeof(dis));    
        cin>>n>>m>>w_m;    
        int countt = 0;    
        for(int i = 1; i <= m; i++)    
        {    
            int u, v, w;    
            cin>>u>>v>>w;    
            e[countt].s = e[countt+1].e = u;    
            e[countt].e = e[countt+1].s = v;//bi-directional    
            e[countt++].t = w;    
            e[countt++].t = w;    
        }    
        for(int j = 1; j <= w_m; j++)    
        {    
            int u, v, w;    
            cin>>u>>v>>w;    
            e[countt].s = u;    
            e[countt].e = v;    
            e[countt++].t = -w;//pay attention    
        }    
            
        if (bellman(countt)) {    
            cout << "YES" << endl;    
        }    
        else cout << "NO" << endl;    
    }    
}   
