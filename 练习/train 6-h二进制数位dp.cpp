#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;
int a[1000100]={1,1,2};
int flag(0);
int main()
{

int n;cin>>n;
for(int i=flag;i<=n;++i)
{
if(i&1) a[i]=a[i-1]%1000000000;
else a[i] = (a[i-2]+a[i>>1])%1000000000;
}
flag = n;
cout<<a[n]<<endl;

return 0;
}
