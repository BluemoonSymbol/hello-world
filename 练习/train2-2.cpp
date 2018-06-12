#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int i,j,k;
    char ch[10];
    scanf("%s",ch);
    int n=strlen(ch);
    sort(ch,ch+n);
    
    int count=0;
    while (count!=-1)
    {
        printf("%s\n",ch);
        count=-1;
        for (i=n-1;i>0;i--)
        {
            if(ch[i]>ch[i-1])
            {
                count=i-1;
                for(j=n-1;j>=0;j--)
                {
                    if(ch[j]>ch[count])
                    {
                        char tmp=ch[j];
                        ch[j]=ch[count];
                        ch[count]=tmp;
                        
                        for (k=i;k<=(i+n-1)/2;k++)  
                        {                                               
                            tmp=ch[k];
                            ch[k]=ch[n-1+i-k];
                            ch[n-1+i-k]=tmp;
                        }
                        break;
                    }
                }
                break;
            }
        }
    } 

    return 0;
}
