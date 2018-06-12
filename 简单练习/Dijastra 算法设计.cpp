#include<cstdio>  
#include<iostream>  
using namespace std;  
#define MAX 500  
#define INFE 1<<20  
   
int N;   
int map[MAX][MAX],b[MAX],path[MAX][MAX];  //path[i][j]��¼·��  
   
void init()  
{  
       int i,j;  
       for(i=1;i<=N;i++)  
              for(j=1;j<=N;j++)  
              {  
                     map[i][j]=INFE;  
                     path[i][j]=j;  
              }  
}  
   
void floyd()  
{  
       int i,j,k;  
       for(k=1;k<=N;k++)  
              for(i=1;i<=N;i++)  
                     for(j=1;j<=N;j++)  
                            if(map[i][j]>map[i][k]+map[k][j])  
                            {  
                                   map[i][j]=map[i][k]+map[k][j];  
                                   path[i][j]=path[i][k];  
                            }  
}  
   
   
int main()  
{  
       int m,u,v,len,s,t;  
       scanf("%d%d%d%d",&N,&m,&s,&t); //����������� �� ��·����  
        
              init();//��ʼ��  
              while(m--)  
              {  
                     scanf("%d%d",&u,&v);  
                     map[u][v]=map[v][u]=1;  
              }  
              floyd();//����ÿ�Խڵ������С·��  
 
                     cout<<map[s][t]<<endl;  
                
         
       return 0;  
}  

