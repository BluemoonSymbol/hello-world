#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
struct ma
{
    int x,y,num;
}a[100];

int vis[10][10],b[8][2]={1,2,1,-2,-1,2,-1,-2,2,1,-2,1,2,-1,-2,-1};  

int main()
{
	int yy[3]={0,9,8};
	sort(yy,yy+3) ;
    char ch1,ch2;
    int x1,x2,y1,y2;
    queue<ma>q;
    while(cin>>ch1>>x1>>ch2>>x2)
	{
        y1=(ch1-'a'+1);
        y2=(ch2-'a'+1);
        memset(vis,0,sizeof(vis));
        int ans=0,flag=0;
        while(q.empty()==0)
        {
        	q.pop();
		}
        
        q.push(ma{x1,y1,0});
        vis[x1][y1]=1;
        while(q.empty()==0)
		{
            ma t=q.front();
            q.pop();
            if(t.x==x2&&t.y==y2)
			{
                    ans=t.num;
                    flag=1;
                    break;
            }
            for(int i=0;i<8;i++)
			{
                int tx=t.x+b[i][0];
                int ty=t.y+b[i][1];
                if(tx<1||tx>8||ty<1||ty>8||vis[tx][ty])
                {
                	continue;
				}
                    
                q.push(ma{tx,ty,t.num+1});
                vis[tx][ty]=1;
            }
            if(flag==1)
                break;
        }
        printf("To get from %c%d to %c%d takes %d knight moves.\n",ch1,x1,ch2,x2,ans);

    }
    return 0;
}

