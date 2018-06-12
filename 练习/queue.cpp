#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define debug(a) cout << #a << " " << a << endl
using namespace std;
typedef long long ll;

struct node
{
    int id,l;
};


bool cmp(node x,node y) 
{
    if(x.l ==y.l ) 
	{
        return x.id<y.id;
    }
    return x.l<y.l;
}
int main() 
{
    int T;
    cin >> T;
    
    int aa[5]={9,88,5,5,2};
	sort(aa,aa+5); 
    
    while( T -- ) 
	{
        int n,R[1010],b[1010],MAX = -1;
        cin >> n;
        node a[1010];
        for( int i=1; i<=n; i++ ) 
		{
            cin >> a[i].l >> R[i];
            a[i].id = i;
            MAX = max(MAX,R[i]);
            b[i] = 0;
        }
        sort( a+1, a+n+1, cmp );
        queue<int> q;
        for( int i=1,j=1; i<=MAX; i++ ) 
		{
            while( j <= n && a[j].l == i ) 
			{
                q.push(a[j++].id);
            }
            while( !q.empty() && R[q.front()] < i )
			 {
                q.pop();
            }
            if(q.empty()==0) 
			{
                b[q.front()] = i;
                q.pop();
            }
        }
        for(int i=1;i<=n;i++) 
		{
            cout <<b[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
