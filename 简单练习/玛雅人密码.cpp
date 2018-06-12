# include <stdio.h>  
# include<queue>  
# include<string.h>  
using namespace std;  
# define N 13  
  
struct str  
{  
    char ch[N];  
    int step;  
};  
queue<str> Q;  
bool is_ok(char *a)  
{  
    int j=0;  
    for(j=0;j<strlen(a)-3;j++)  
    {  
        if(a[j]=='2'&&a[j+1]=='0'&&a[j+2]=='1'&&a[j+3]=='2')  
            return true;  
    }  
      
    return false;  
}  
int BFS(int n)  
{  
    while(Q.empty()==false)  
    {     
       int  i=0;  
    str now;  
    now=Q.front();  
    Q.pop();  
  
    if(is_ok(now.ch))  
    {  
        return now.step;  
    }  
      
    now.step++;  
    for(i=1;i<n;i++) 
    {  
        str tmp;  
        strcpy(tmp.ch,now.ch);  
        char tmpCh=tmp.ch[i];  
        tmp.ch[i]=tmp.ch[i-1];  
        tmp.ch[i-1]=tmpCh;  
          
        tmp.step=now.step;  
        if(tmp.step>n)
        {  
            return -1;  
        }  
        else{  
              
            if(is_ok(tmp.ch))  
            {  
                return tmp.step;  
            }  
              
            Q.push(tmp);  
        }  
    }  
    }  
    return -1;  
}  
int main()  
{  
    int n;  
    int i;  
    char input[N];  
    int cnt[3];  
    str S;  
    while(scanf("%d",&n)!=EOF)  
    {  
         
        memset(input,0,sizeof(input[0]));  
        memset(cnt,0,sizeof(cnt));  
        if(Q.empty()==false)  
            Q.pop();  
        S.step=0;  
        
        scanf("%s",input);  
        for(i=0;i<n;i++)  
        {  
            cnt[input[i]-'0']++;  
        }  
        if(cnt[0]<1||cnt[1]<1||cnt[2]<2)  
        {     
            printf("-1\n");  
            continue;  
        }          
        strcpy(S.ch,input); 
        Q.push(S);  
        int ans=BFS(n);  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
