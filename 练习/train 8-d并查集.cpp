#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<iostream>    
#include<cstdlib>  
#include<algorithm>  
#include<string>  

  
using namespace std;  
    
int n, m, k;  
int parent[30010];  
int total[30010];  
  
int getparent(int a)  
{  
    if (parent[a] != a)  
        parent[a] = getparent(parent[a]);  
    return parent[a];  
}  
void merge(int a, int b)  
{  
    int p1 = getparent(a);  
    int p2 = getparent(b);  
    if (p1 == p2)  
        return;  
    total[p1] += total[p2];  
    parent[p2] = p1;  
}  
  
int main() 
{  
    while (~scanf("%d%d",&n,&m))
	 {  
        if (n==0 && m==0) break;  
        for (int i=0; i<n; i++) 
		{  
            parent[i] = i;  //初始化节点 
            total[i] = 1;  
        }  
        for (int i=0; i<m; i++)  
        {  
            int h, s;  
            cin>>k>>h;  //分开输入 
            for(int j=1;j<k;j++)
			 {  
                cin>>s;  
                merge(h, s);  
            }  
        }  
        cout << total[getparent(0)] << endl;  
    }  
    return 0;  
}  


