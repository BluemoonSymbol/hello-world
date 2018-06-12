#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#define N 10005  
  
using namespace std;  
  
typedef struct note 
{  
    int u, v, w;  
}edge;  
  
edge e[N];  
  
int n, m;  
int sum, cnt;  
int f[N];  
  
int cmp(edge a, edge b)  
{  
    return a.w < b.w;  
}  
  
void init()  
{  
    sum = 0; cnt = 0;  
    for (int i = 1; i <= n; i++)  
        f[i] = i;  
}  
  
int find(int x)  
{  
	if(x==f[x])
	{
		return x;
	}
	find(f[x]);
     
}  
  
int merge(int x, int y)  
{  
    int t1 = find(x), t2 = find(y);  
    if (t1 != t2)  
    {  
        f[t2] = t1;  
        return 1;  
    }  
    return 0;  
}  
  
int kruskal()  
{  
    init();  
    for (int i = 0; i < m; i++)  
    {  
        if (merge(e[i].u, e[i].v))  
        {  
            cnt++;  
            sum += e[i].w;  
        }  
        if (cnt == n - 1)  
            break;  
    }  
    if (cnt < n - 1) return -1;  
    else return sum;  
}  
  
int main()  
{  
    while (~scanf("%d", &n) && n)  
    {  
        scanf("%d", &m);  
        int t1, t2, t3, ans;  
        for (int i = 0; i < m; i++)  
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);  
        sort(e, e + m, cmp);
        ans = kruskal();  
        printf("%d\n", ans);  
    }  
    return 0;  
} 
