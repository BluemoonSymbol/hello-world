#include<stdio.h>  
#include<iostream>  
#include<cmath>
#include<cstring>
#include<algorithm>  

using namespace std;  

struct sh
{
    unsigned long cnts;
    unsigned long cnth;
    int ns;
    sh():cnts(0),cnth(0),ns(0) {}
}str[100005];

bool cmp(sh a, sh b) {
    unsigned long tempa = a.cnts*b.cnth;//用unsigned long 暂存结果
    unsigned long tempb = a.cnth*b.cnts;
    if (tempa >tempb)return true;
    else if (tempa < tempb)return false;
    else {//“相等”的情况
        //把含's'更多的字符串放在前面，能与其他字符串生成更多的sh子串
        if (a.cnts > b.cnts)
        return true;
        if (a.cnts < b.cnts)return false;
        else {
            return a.cnth < b.cnth;
        }
    }

} 
char d;


int main() {
    int n;
    long long  ans=0, ts=0, th=0;
    scanf("%d", &n);
    scanf("%c", &d);//额外的换行符

    for (int i = 0; i < n;++i) {
        while (1)
        {
            scanf("%c", &d);
            if (d == 's')str[i].cnts++;
            else if (d == 'h') { str[i].cnth++; str[i].ns += str[i].cnts; }
            else break;//读取到回车，一个输入结束
        }
    }
    sort(str, str + n, cmp);//按我们定义的先后关系排序
    //最后的计算，用ts记录当前位置前面已经有多少个s
    for (int i = 0; i < n; ++i) {
        //加上这个字符串的内部sh子串数
        ans += str[i].ns;
        //这个字符串与前面的所有的字符串产生sh子串数
        ans += ts*str[i].cnth;
        //更新ts
        ts += str[i].cnts;
    }

     printf("%I64d\n", ans);
}




