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
    unsigned long tempa = a.cnts*b.cnth;//��unsigned long �ݴ���
    unsigned long tempb = a.cnth*b.cnts;
    if (tempa >tempb)return true;
    else if (tempa < tempb)return false;
    else {//����ȡ������
        //�Ѻ�'s'������ַ�������ǰ�棬���������ַ������ɸ����sh�Ӵ�
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
    scanf("%c", &d);//����Ļ��з�

    for (int i = 0; i < n;++i) {
        while (1)
        {
            scanf("%c", &d);
            if (d == 's')str[i].cnts++;
            else if (d == 'h') { str[i].cnth++; str[i].ns += str[i].cnts; }
            else break;//��ȡ���س���һ���������
        }
    }
    sort(str, str + n, cmp);//�����Ƕ�����Ⱥ��ϵ����
    //���ļ��㣬��ts��¼��ǰλ��ǰ���Ѿ��ж��ٸ�s
    for (int i = 0; i < n; ++i) {
        //��������ַ������ڲ�sh�Ӵ���
        ans += str[i].ns;
        //����ַ�����ǰ������е��ַ�������sh�Ӵ���
        ans += ts*str[i].cnth;
        //����ts
        ts += str[i].cnts;
    }

     printf("%I64d\n", ans);
}




