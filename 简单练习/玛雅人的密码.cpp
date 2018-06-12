#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

int pan(string a,int n)
 {
int flag=0;
for(int i=0; i<n-3; i++)
 {
	if(a[i]=='2'&&a[i+1]=='0'&&a[i+2]=='1'&&a[i+3]=='2')
 	{
		flag=1;
 		break;
	}
 }
return flag;
}

string swap(string a,int i,int j)
{
 char temp=a[i];
 a[i]=a[j];
 a[j]=temp;
 return a;
}

struct info
 {
 string a;
 int t;
};
queue<info> Q;


int bfs(int n)
{
 while(Q.empty()==false) 
 {
 info now=Q.front();
 Q.pop();
 if(pan(now.a,n))
 {
 return now.t;
 }
 else
 {
 for(int i=0; i<n-1; i++)
  {
 string new_a=swap(now.a,i,i+1);
 int new_t=now.t+1;
 if(new_t>20)
  {
 return -1;
 } else {
 if(pan(new_a,n)) 
 {
 return new_t;
} 
else 
{
 info tmp;
 tmp.a=new_a;
 tmp.t=new_t;
 Q.push(tmp);
}
}
 }
 }
}
 return -1;
}
int main()
 {
int n;
string str;
 while(cin>>n>>str)
  {
while(Q.empty()==false)
{
 Q.pop();
 }
 info tmp;
tmp.a=str;
 tmp.t=0;
 Q.push(tmp);
 int ans=bfs(n);
cout<<ans<<endl;
 }
 return 0;

