#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>


using namespace std;
int main()
{
int i,j,k;
char s[10][20]={".........",".--**-**--",".-*--*--*-",".-*-----*-",".--*---*--",".---*-*---",".----*----"}; 
int x,y,w,h;

//for(i=1;i<=7;i++)
//{
//	for(j=1;j<=9;j++)
//	{
//		cout<<s[i][j];
//		
//		
//	}
//	cout<<endl;
//	
//}

cin>>x>>y>>w>>h;


if(x<1||x>9||y<1||y>6||w<1||w>9||h<1||h>6||(x+w)<2||(x+w)>10||(y+h)>7||(y+h)<2)
{
	cout<<"Input Error";
	return 0;
}

for(i=y;i<=y+h-1;i++)
{
	for(j=x;j<=x+w-1;j++)
	{
		cout<<s[i][j];	
	}
	cout<<endl;
	
}


return 0;
} 
