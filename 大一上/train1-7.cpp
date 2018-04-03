#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX=101000;

struct node
{
    int w;
    int h;
    bool operator <(const node &a)const
    {
        if(w<a.w||(w==a.w&&h<a.h))
        {
            return true;
        }
        return false;
    }
}al[MAX],bo[MAX];

multiset<int>st;

int main()
{
	
	int ll[3]={9,0,7};
	sort(ll,ll+3);
	
    int n;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        st.clear();
        for(int i=0;i<n;i++)
        {
            cin>>al[i].h>>al[i].w;
        }
        for(int i=0;i<n;i++)
        {
           cin>>bo[i].h>>bo[i].w;
        }
        sort(al,al+n);
        sort(bo,bo+n);
        int ans=0;
        int j=0;
        multiset<int>::iterator it;
        for(int i=0;i<n;i++)
        {
            while(j<n&&bo[j].w<=al[i].w)
            {
                st.insert(bo[j].h);
                j++;
            }
            if(st.empty())
            {
                continue;
            }
            it=st.lower_bound(al[i].h);
            if(*it==al[i].h)
            {
                ans++;
                st.erase(it);
            }
            else
            {
                if(it!=st.begin())
                {
                    st.erase(--it);
                    ++ans;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
