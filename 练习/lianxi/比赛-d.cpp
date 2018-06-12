#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
        {
            int a[50];
            memset(a,0,sizeof(a));
            long long n,nn;
            cin>>nn;
            nn--;
            n=nn;
            int i=0;
            while (n>0)
                {
                    a[i]=n%6;
                    i=i+1;
                    n=n/6;
                }
            int s=i-1;
            for(int is=s; is>=0; is--)
                {
                    if(a[is]==5)a[is]=9;
                    else if(a[is]==4)a[is]=8;
                    else if(a[is]==3)a[is]=6;
                    else if(a[is]==2)a[is]=4;
                    cout<<a[is];
                }
            if(nn==0)
                cout<<0;
            cout<<endl;
        }
}

