#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<windows.h>

const int a=10;
int b=10;


using namespace std;

void gotoxy(int x, int y) 
{
    int xx=0x0b;
    HANDLE hOutput;
    COORD loc;
    loc.X = x;
    loc.Y=y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, loc);
    return;
}

void love()
{
	
	gotoxy(a,b);
	b+=4;
	printf("I love you,do you love me?\n");
	int a;
	printf("If you love me,please push 1!\n");
	scanf("%d",&a);
	if(a==1)
	{
		printf("It's my plaesure.");
		
		system("pause");
		
	}
	else
	{
		printf("Oh honey,it's not the right answer.\n");
		getchar(); 
		love();
	}
}

int main()
{
	system("color 1c");
	love();
	return 0;
}

