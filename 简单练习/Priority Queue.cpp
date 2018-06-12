#include<cstdio>  
#include<algorithm>  
#include<cmath>  
#include<cstring>  
#include<iostream> 
#include<queue> 
using namespace std;   

struct node  
{  
    friend bool operator< (node n1, node n2)  
    {  
        return n1.priority < n2.priority;
    }  
    
    int priority;  
    int value;  
}; 

int main()
{
	
	int m;
	cin>>m;
	
	priority_queue<int, vector<int>, greater<int> > v;
	
	while(m--)
	{
		char a;int x;
		cin>>a;
		switch(a)
		{
			case 'I':
				{
					cin>>x;
					v.push(x);
					break;

				}
			case 'D':
				{
					v.pop();
					break;
				}
			case 'Q':
				{
					cout<<v.top()<<endl;
					break;
				}		
		}
	}	
	
	
	return 0;
}



