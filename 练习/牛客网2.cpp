#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;


typedef struct 
{
	int x,y;
	
}P;
P a[35];

int main()
{
	
	int n;
	cin>>n;
	
	
		int i,j,k;
		for(i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y;	
		}
		for(i=1;i<=n;i++)
		{
	//		cout<<a[i].x<<"   "<<a[i].y<<endl;	
		}
		int cnt1=0,cnt2=0;
	for(i=2;i<=n-1;i++)
	{
			int tmp;
			tmp=(a[i].x-a[i-1].x)*(a[i+1].y-a[i].y)-(a[i].y-a[i-1].y)*(a[i+1].x-a[i].x);
			if(tmp<0)
			{
				cnt1++;
			}
			if(tmp>0)
			{
				cnt2++;
			}
	}
		int t[3];
		t[1]=(a[1].x-a[n].x)*(a[2].y-a[1].y)-(a[1].y-a[5].y)*(a[2].x-a[1].x);
		t[2]=(a[n].x-a[n-1].x)*(a[1].y-a[n].y)-(a[n].y-a[n-1].y)*(a[1].x-a[n].x);
		for(i=1;i<=2;i++)
		{
			if(t[i]<0)
			{
				cnt1++;
			}
			if(t[i]>0)
			{
				cnt2++;
			}
		}
	//	cout<<cnt1<<"   "<<cnt2<<endl;
		if(cnt1<cnt2)
		{
			cout<<"counterclockwise";
		}
		else
		{
			cout<<"clockwise";
		}
		

	return 0;

}
