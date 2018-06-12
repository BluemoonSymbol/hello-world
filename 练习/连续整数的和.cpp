#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n,i,j,k;
    cin>>n;
    
    int m = (int)sqrt(n);
    int s = 0;
    for(i=m*2+1;i>1;i--)
    {
        if((2*n+i-i*i)%(2*i)==0&&(2*n+i-i*i)>0)
        {
            cout<<(2*n+i-i*i)/(i*2)<<endl;
               s++;
        }
    }
    if(s==0)
    {
    	cout<<"No Solution";
	}
          
    
    return 0;
}
