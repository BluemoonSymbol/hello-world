#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std; 

#define clr(a,  x) memset(a,  x, sizeof(a))  
typedef long long ll;  
typedef long double ld;  
  
using namespace std;  
  
const int maxn = 110007;  
char ma[maxn*2];  
int mp[maxn*2];  
  
  
void manacher(char s[], int len)
{  
    int l = 0;  
    ma[l++]='$';  
    ma[l++]='#';  
    for(int i = 0 ; i < len; i++)
	{  
        ma[l++] = s[i];  
        ma[l++] = '#';  
    }  
    ma[l] = 0;  
    int mx = 0, id = 0;  
    for(int i=0; i<l; i++)
	{  
        mp[i] = mx>i ? min(mp[2*id-i],mx-i): 1;  
        while(ma[i+mp[i]] == ma[i-mp[i]])mp[i]++;  
        if(i+mp[i]>mx){  
            mx = i + mp[i];  
            id = i;  
        }  
    }  
}  
  
int main()
{  
    char s[maxn];  
    while(scanf("%s",s)==1)
	{  
        int len = strlen(s);  
        manacher(s,len);  
        int ans = 0;  
        for(int i = 0; i < 2*len+2; i++)
		{
			 ans = max(ans, mp[i]-1);
		  }  
             
        printf("%d\n", ans);  
    }  
    return 0;  
}  

