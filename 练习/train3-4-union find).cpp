#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

template<typename T> T Max(T a, T b){ return a > b ? a : b; }
const int MAXN = 1001 + 10;
struct node
{
    int x, y;
}num[MAXN];
int par[MAXN];
int r[MAXN];
int ok[MAXN];
int tot;

int find(int i)
{
    while (par[i] != i)
	{
        i = par[i];
    }
    return i;
}

bool cal(int a, int b, int D)
{
    if (pow(double(num[a].x - num[b].x), 2) + pow(double(num[a].y - num[b].y), 2) <= D*D)
	{
        return true;
    }
    else
        return false;
}
void Link(int a, int b)
{
    a = find(a);
    b = find(b);
    if (r[a] < r[b])
	{
        par[a] = b;
    }
    else
	{
        par[b] = a;
        if (r[a] == r[b])
            r[a]++;
    }
}
int main()
{
    int N, D;
    scanf("%d%d", &N, &D);
    for (int i = 0; i < MAXN; i++)
    {
    	par[i] = i;
	}
        
    tot = 0;
    memset(r,0,sizeof(r));
    for (int i = 1; i <= N; i++)
	{
        scanf("%d%d", &num[i].x, &num[i].y);
    }
    char str[5];
    while (~scanf("%s", str))
	{
        int a, b;
        if (str[0] == 'O')
		{
            scanf("%d", &a);
            for (int i = 0; i < tot; i++)
			{
                
                if (cal(ok[i], a, D))
				{
                    Link(ok[i], a);
                    
                }
            }
            ok[tot++] = a;
        }
        else{
            scanf("%d%d", &a, &b);
            
            if (find(a) == find(b))
			{
                printf("SUCCESS\n");
            }
            else
			{
                printf("FAIL\n");
            }
        }
    }
    return 0;
}
