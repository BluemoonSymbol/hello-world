#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 

long long  int Q, T;
int ans[300];
int tail = 0;

int dfs(long long int a)
{
    if(a<=9)
    {
        ans[tail++] = a;
        return 1;
    }
    for(int i=9; i>=2;i--)
    {
        if(a%i==0)
        {
            ans[tail++]=i;
            return dfs(a/i);
        }
    }
    return 0;
}

int main()
{
    cin >> T;
    while(T--)
    {
        memset(ans, 0, sizeof(ans));
        tail = 0;
        cin >> Q;
        if(Q==0)
        {
            cout << 10 << endl;
            continue;
        }
        if(Q==1)
        {
            cout << 1 << endl;
            continue;
        }
        if(dfs(Q))
        {
            sort(ans, ans + tail);
            for (int i = 0; i < tail;i++)	 
            cout << ans[i];
            cout << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}
