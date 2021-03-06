#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector> 

using namespace std;

typedef vector<int> vec;  
typedef vector<vec> mat;  
int n;  
mat mul(mat& A ,mat& B)  
{  

    mat C(A.size(),vec(B[0].size()));  
    for(int i = 0;i<A.size();i++)  
    {  
        for(int k = 0;k<B.size();k++)  
        {  
            for(int j = 0;j<B[0].size();j++)  
            {  
                C[i][j] = (C[i][j]+A[i][k]*B[k][j])%10007;  
            }  
        }  
    }  
    return C;  
}  
  
mat pow(mat A,long long n)  
{  
    mat B(A.size(),vec(A.size()));  
    for(int i = 0 ;i<A.size();i++)  
    {  
        B[i][i]=1;  
    }  
    while(n>0)  
    {  
        if(n & 1)  
        {  
            B=mul(B,A);  
        }  
        A=mul(A,A);  
        n>>=1;  //����һλ; 
    }  
    return B;  
}  
void solve()  
{  
    mat A(3,vec(3));  
    A[0][0] = 2; A[0][1] = 1; A[0][2] = 0;   
    A[1][0] = 2; A[1][1] = 2; A[1][2] = 2;   
    A[2][0] = 0; A[2][1] = 1; A[2][2] = 2;  
    A = pow(A,n);  
    cout<<A[0][0]<<endl;  
}  

int main()  
{  
    int Case;  
    cin>>Case;  
    while(Case--)  
    {  
        cin>>n;  
        solve();  
    }  
}  
