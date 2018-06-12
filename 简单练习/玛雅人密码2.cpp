#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
int MIN = 10000;
int N;
int dir[12][4] = {2,0,1,2,2,1,0,2,0,2,1,2,2,0,2,1,1,2,0,2,2,1,2,0,0,1,2,2,0,2,2,1,2,2,0,1,1,0,2,2,1,2,2,0,2,2,1,0};
int value[12] = {0,1,1,1,2,2,2,2,2,3,3,3};
char s[100];
int main()
{
	while(cin>>N>>s)
	{
		MIN = 100;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<12;j++)
			{
				if(s[i]==dir[j][0]+48)
				{
					int step = 1;
					for(int k=i+1;k<N;k++)
					{
						if(s[k]==dir[j][step]+'0')
						{

							if(step==3)
							{
								MIN = min(MIN,value[j]+k-i-3);
							
							}
							step++;
						}
					}
				}
			}
		}
		if(MIN!=100)
		cout<<MIN<<endl;
		else
		cout<<"-1"<<endl;
		memset(s,0,sizeof(s));
	}
	return 0;
}
