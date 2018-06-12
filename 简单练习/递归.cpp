#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;


bool dfs(int a[], int b[], int f, int n)//b用来标记a中的元素是否用过； 
 {
	if (f==n) 
	{
		cout<<"--> ";
		for (int k=0;k<n;k++) 
		{
			if (b[k]==1) 
			{
				cout<<a[k]<<" ";
			}
		}
		cout<<endl;
		return 0;
	}	
	b[f]=1;
	//cout<<"f="<<f; 
	dfs(a, b, f + 1, n); //return返回到的地方back tracking
	b[f]=0;//取消f处的标记； 
	dfs(a, b, f + 1, n);
}


int main()
{
	int m,i,j,k;
	cin>>m;
	for (i = 0; i<m; i++) 
	{
		int n;
		cin>>n;
		int b[1000]={0};
		int a[1000]={0};
		
		for (j=0;j<n;j++)
		 {
			cin>>a[j];
		 }	
		dfs(a,b,0,n);
	}
	
	return 0;
}

		
		

