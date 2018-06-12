#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <math.h>  
#include <stack>  
#include <queue>  
#include <vector>  
#include <algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  

using namespace std;  


int map[10][10];  
int num;  
struct zb
{  
    int x,y;  
} a[100];  
int jc(int k,int step)  
{  
    int x,y;  
    for(int i=0; i<9; i++)  
        if(map[a[step].x][i]==k||map[i][a[step].y]==k)
            return 0;  
    x=(a[step].x/3)*3;  
    y=(a[step].y/3)*3;  
    
    for(int i=x; i<x+3; i++)
    {
    	for(int j=y; j<y+3; j++) 
		{
			if(map[i][j]==k)  
                return 0;  
		 } 
	}
        
            
    return 1;  
}  
void dfs(int step)  
{  
    if(step==num)
    {  
        for(int i=0; i<9; i++)  
        {  
            for(int j=0; j<8; j++)  
                cout<<map[i][j]<<" ";  
            cout<<map[i][8]<<endl; 
        }  
        return;  
    }  
    for(int i=1; i<=9; i++)
    {  
        if(jc(i,step))
        {  
            map[a[step].x][a[step].y]=i; 
            dfs(step+1);
            map[a[step].x][a[step].y]=0;  
        }  
    }  
    return;  
}  
int main()  
{  
    int q=0;  
    char s;  
    while(cin>>s)
    {  
        num=0;  
        if(s=='?') 
        {  
            a[num].x=0;  
            a[num].y=0;  
            num++;  
            map[0][0]=0;  
        }  
        else  
            map[0][0]=s-'0';  
        for(int i=0; i<9; i++)  
        {  
            for(int j=0; j<9; j++)  
            {  
                if(i==0&&j==0)continue;  
                cin>>s;  
                if(s=='?')  
                {  
                    a[num].x=i;  
                    a[num].y=j;  
                    num++;  
                    map[i][j]=0;  
                }  
                else  
                    map[i][j]=s-'0';  
            }  
        }  
        if(q++)
            cout<<endl;  
        dfs(0); 
    }  
    return 0;  
}  
