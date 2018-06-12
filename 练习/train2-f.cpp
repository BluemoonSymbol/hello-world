#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;
typedef long long LL;
typedef long double LD;
 
const int N=108, INF=0x3F3F3F3F, EPS=0.4;
 
struct herb
{
    LL w, val;
    bool operator<(const herb &tp)const
	{
        return val*tp.w > tp.val*w;
    }
 
}pk[N];
 
 
int n;
LL sum[N], sw[N], lim;
LL ans;
 
int dfs(int d,LL w,LL val)
{
    if(val>ans)
	{
        ans =val;
    }
    if(d >= n)
	{
        return 0;
    }
    if(val+(LD)pk[d].val/(LD)pk[d].w*(lim-w)+EPS<=ans)
	{
        return 0;
    }
 
    if(w+pk[d].w<= lim)
	{
        dfs(d+1,w+pk[d].w,val+pk[d].val);
    }
    dfs(d+1,w,val);
 
}
 
int main()
{
	int i,j,k;
    while(~scanf("%d %I64d", &n, &lim))
	{
        for(i=0;i<n;i++)
		{
            scanf("%I64d %I64d", &pk[i].w, &pk[i].val);
        }
        sort(pk, pk + n); 
       sum[n] = 0;
        sw[n] = 0;
        ans = 0;
        dfs(0, 0, 0);
        printf("%I64d\n",ans);
 
    }
    return 0;
}
