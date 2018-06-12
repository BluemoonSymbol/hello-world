#ifndef _HAFFMANTREE_H
#define _HAFFMANTREE_H

/*
实现对赫夫曼编码主要步骤：
生成一个节点数组用来存放树的节点信息
初始化
从中找出权值最小和权值次小节点然后生成这两个节点的双亲节点权值最小节点是该双亲节点的左孩子次小为右孩子然后将该双亲节点加入到节点数组中并标记为已加入
重复三步骤知道赫夫曼树构造成功
*/
#include<stdio.h>
#include<malloc.h>
#define LEN_CODE sizeof(HaffmanCode)
#define LEN_NODE sizeof(haffmannode)
#define MAXWEIGHT 1000 //用来存储最大的权值数
#define MaxBits 30 //用来存储转化后的编码

typedef struct HaffManTree
{
    int weight;  //存放节点的权值
    int LeftChild,RightChild,Parent;  //采用仿真指针方法存放节点的左右孩子和双亲下标
    int flag;  //用来判断该节点是否已经加入了赫夫曼树中( 0表示未加入，1表示已经加入 )
}haffmannode;

typedef struct HaffMancode
{
    int bits[MaxBits]; //用来存放编码
    int weight;  //用来存放对应的权值
    int start; //存放编码的起始位置
}HaffmanCode;

void MakeTree(int weight[],int n,haffmannode haffmantree[]);
void MakeCode(haffmannode haffmantree[],int n,HaffmanCode haffmancode[]);
void DispCode(char temp[],haffmannode tree[],HaffmanCode Code[],int n);

#endif
/*
功能函数的实现
*/
//#include"haffman.h"

void MakeTree(int weight[],int n,haffmannode haffmantree[])
{
    int i,j,m1,m2,x1,x2;
    //初始化（n个叶节点一共 2*n-1 个节点）
    for(i=0;i < 2*n-1; i++)
    {
        if(i < n)  //处理 n 个叶子节点
        {
            haffmantree[i].weight=weight[i];
        }
        else haffmantree[i].weight=0;
        haffmantree[i].LeftChild=-1;  //开始时候让左右孩子和双亲的下标为 -1 
        haffmantree[i].RightChild=-1;
        haffmantree[i].Parent=-1;
        haffmantree[i].flag=0;  
    }
    
    //每次从中选出权值最小的和次小的构成树的左右子树
    //处理 n-1 个非叶子节点
    for(i=0; i < n-1;i++)
    {
        m1=m2=MAXWEIGHT;
        x1=x2=0;
        //从有权值的节点中查找 m1 用来存放权值最小的 m2 用来存放权值次小的 x1 用来存放权值最小的下标 x2 用来存放权值次小的下标
        for(j=0;j < n+i; j++)
        {
            if(haffmantree[j].weight < m1 && haffmantree[j].flag==0)
            {
                m2=m1; 
                x2=x1;
                m1=haffmantree[j].weight;
                x1=j;
            }
            else if(haffmantree[j].weight < m2 && haffmantree[j].flag==0)
            {
                m2=haffmantree[j].weight;
                x2=j;
            }
        }
        haffmantree[x1].Parent=n+i; // 比如第一个双亲节点的下标就是 n 第二个双亲节点的下标就是 n+1 --------
        haffmantree[x2].Parent=n+i;
        haffmantree[x1].flag=1;
        haffmantree[x2].flag=1;
        haffmantree[n+i].weight=haffmantree[x1].weight + haffmantree[x2].weight;  //权值求和
        //printf("%d\n",haffmantree[n+i].weight);
        haffmantree[n+i].LeftChild=x1;
        haffmantree[n+i].RightChild=x2;    
    }
}

//本函数用来实现对赫夫曼编码的解决
void MakeCode(haffmannode haffmantree[],int n,HaffmanCode haffmancode[])
{
    int i,j;
    int Child,Parent;
    HaffmanCode *code;
    code=(HaffmanCode *)malloc(LEN_CODE);  //用来存放临时数据
    for(i=0;i < n ;i++)
    {
        code->weight=haffmantree[i].weight;
        code->start=0; 
        Child=i;    
        Parent=haffmantree[Child].Parent;
        while(Parent != -1) //当双亲节点不为根节点时候
        {
            if(haffmantree[Parent].LeftChild==Child)  //如果当前节点是双亲节点的左孩子就将0加入到该编码中如果是右孩子就将1加入到编码中
                code->bits[code->start]=0;
            else
                code->bits[code->start]=1;
            code->start++;  
            Child=Parent;  //自底向上移动判断
            Parent=haffmantree[Child].Parent;
        }
        for(j=0;j < code->start;j++) //把该编码加入到对应的编码数组中
        {
            haffmancode[i].bits[j]=code->bits[j];
        }
        haffmancode[i].weight=code->weight; //把对应的权值加入到对应编码数组的权值中去
        haffmancode[i].start=code->start; //将结束位置复制进去
    }
}


void DispCode(char temp[],haffmannode tree[],HaffmanCode Code[],int n) //本函数主要用来实现哈夫曼编码的输出
{
    int i,j;
    printf("\n输出赫夫曼编码:\n\n");
    for(i=0;i<n;i++)
    {
        printf("字符= %c \tWeight= %d \t\n字符= %c \tCode=",temp[i],tree[i].weight, temp[i]);
        for(j=(Code[i].start-1);j>=0;j--)//输出编码
        {
            printf("%d",Code[i].bits[j]);
        }
        printf("\n\n");
    }
}
