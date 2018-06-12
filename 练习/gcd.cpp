#include <iostream>  
#include <algorithm>  
#include <cstdio>  
#include <cstring>  
#include <string>  
using namespace std;  
  
const int INF=999999999;  
string in;  
  
int tran(int a,int b) 
{  
    if(a>b)  
        return 0;  
    int res=0;  
    for(int i=a;i<=b;++i)  
        res=res*10+in[i]-'0';  
    return res;  
}  
  
int main()  
{  
    while(cin>>in&&in!="0")  
    {  
        int ans_up=INF,ans_down=INF;  
        int len=in.size();  
        len-=3;  
        for(int i=len-1;i>=2;--i)  
        {  
            int up=tran(2,len-1)-tran(2,i-1),down=0;  
            for(int j=i;j<len;++j)
			{
				down=down*10+9;
			  }  
                  
            for(int j=2;j<i;++j)
			{
				down*=10;
			  }  
                  
            int gcd=__gcd(up,down); 
            up/=gcd;  
            down/=gcd;  
            if(down<ans_down) 
            {  
                ans_up=up;  
                ans_down=down;  
            }  
        }  
        printf("%d/%d\n",ans_up,ans_down);  
    }  
      
    return 0;  
}
