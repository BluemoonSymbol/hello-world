#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	char ch[10000];
	cin>>ch;
	int i,j,k,n;
	n=strlen(ch);	
	sort(ch,ch+n);
	int ans[n+1]={0},count=1;
	for(i=0;i<n;i++)
	{
		if(ch[i]==ch[i+1])
		{
			ans[count]++;
		}
		else
		{
			ans[count]++;
			count++;
		}		
	}	
	sort(ans+1,ans+n+1);
	int tmp=26;
	int sum=0;
	for(i=n;i>0;i--)
	{
		sum+=tmp*ans[i];
		tmp--;		
	} 
	cout<<sum;	
	return 0;
}
