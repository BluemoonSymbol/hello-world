#include<stdio.h>
#include<string.h>
#include<windows.h>

void color(short x)    
{  
    if(x>=0 && x<=15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);     
    else 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
}  
int main()
{
	color(3);
	char a[8][7]={	"*****\n",
					"*   *\n",
					"*   *\n",
					"*   *\n",
					"*   *\n",
					"*   *\n",
					"*   *\n",
					"*****",};
		int i,j,k;			
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			printf("%c",a[i][j]);
		}
		
	}
	
	return 0;
	
	
}
