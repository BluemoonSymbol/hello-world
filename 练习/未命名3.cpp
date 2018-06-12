#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>  
#include <map>  
using namespace std; 
  
struct  Key
{  
    
        int number;  
        int start;  
        int end;  
};  
  
int n,k;  
Key s1[1005], s2[1005];  
int index1[1005], index2[1005];  
  
bool cmp1(Key const &k1, Key const &k2)
{  
    if(k1.end < k2.end)  
        return true;  
    else if(k1.end == k2.end && k1.number < k2.number)  
        return true;  
    else  
        return false;  
}  
  
bool cmp2(Key const &k1, Key const &k2)
{  
    if(k1.start < k2.start)  
        return true;  
    else if(k1.start == k2.start && k1.number < k2.number)  
        return true;  
    else  
        return false;  
}  
  
void Pretreatment()
{  
    memset(s1,0,sizeof(s1));  
    memset(s2,0,sizeof(s2));  
    for(int i = 1; i <= n; i++)
	{  
        index1[i] = i;  
        index2[i] = i;  
    }  
    for(int i = 0; i < k; i++)
	{  
        int w,s,c;  
        cin>>w>>s>>c;  
        s1[i].number = s2[i].number = w;  
        s1[i].start = s2[i].start = s;  
        s1[i].end = s2[i].end = s + c;  
    }  
    sort(s1,s1+k,cmp1);  
    sort(s2,s2+k,cmp2);  
}  
  
int find()
{  
    int i = 1;  
    while(index1[i] > 0)  
        i++;  
    return i;  
}  
  
void Print()
{  
    for(int i = 1; i < n; i++)  
            cout<<index1[i]<<' ';  
    cout<<index1[n]<<endl;  
}  
int main()
 {  
    while(cin>>n)
	{  
        cin>>k;  
        Pretreatment();  
        for(int i = 0, j = 0; i < k; i++)
		{  
            int time = s1[i].end;  
            while(s2[j].start < time && j < k)
			{  
                int pos = index2[s2[j].number];  
                index1[pos] = -1;  
                index2[s2[j].number] = -1;  
                j++;  
            }  
            int t = find();  
            index1[t] = s1[i].number;  
            index2[s1[i].number] = t;  
           
        }  
        Print();  
    }  
    return 0;  
}  
