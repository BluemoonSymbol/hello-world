#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;
int a[200000]={0};
int b[200000]={0};
int main()
{
	int n;
    int i,j,k;
   int max;
    cin>>n;
    for(i=1; i<=n; i++)
    {
    cin>>a[i];
    }
    b[1]=a[1];

    max=b[1];

    for(i=2;i<=n;i++)
    {
        if(b[i-1]>0)
        {
        	 b[i]=b[i-1]+a[i];
		}
        else
            b[i]=a[i];

        if(b[i]>max)
        {
        	 max=b[i];
		}
    }

    cout<<max<<endl;

    return 0;
	
	
}
