#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<math.h>
#include<string.h>

#define height 40 
#define wide 40
#define UP 'w' 
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'


int i,j,k;
char ch=UP; //初始方向
int grow=0; //衡量蛇是否长大 
int score=0;
char map[height][wide];
struct Food
{
	int x;
	int y;
}food;

void Pos(int x, int y)//设置光标位置
{
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//返回标准的输入、输出或错误的设备的句柄，也就是获得输入、输出/错误的屏幕缓冲区的句柄
    SetConsoleCursorPosition(hOutput, pos);
}
  
struct Snake
{
	int x[50];
	int y[50];
	int len;
	int speed;
}snake; //snake[0]头 

void init_map(void);
void update_food(void);
void move_snake(void);
int is_alive(void);
void get_speed(void);
void gotoxy(int x, int y);
void colors(void);	
void Start_Game();
void color(short x);
void back(void);
void mapp0(void);
void mapp1(void);
void mapp2(void);
void mapp3(void);
void mapp4(void);
void mapp5(void);
void mapp6(void);
void mapp7(void);
void mapp8(void);
void mapp9(void);



int uu=0;
int t;
int main()
{
	Start_Game();
	colors();
	
	gotoxy(20,20);
	printf("请选择地图"); 
	scanf("%d",&t);
	system("cls");
	gotoxy(20,20);
//	printf("橡皮模式请输入1\n");
	gotoxy(20,21);
//	back();
//	int tmp=0;//printf("uu=%d\n",uu);

//	scanf("%d",&tmp);
	getchar();
//	if(tmp==1)
//	{
//		
//		if(uu>7)
//		{
//			color(10);
//		}
//		else
//		{
//			color(8);
//		}
//	} 
	system("cls");
	
	switch(t)
	{
		case 0:mapp0();break;
		case 1:mapp1();break;
		case 2:mapp2();break;
		case 3:mapp3();break;
		case 4:mapp4();break;
		case 5:mapp5();break;
		case 6:mapp6();break;
		case 7:mapp7();break;
		case 8:mapp8();break;
		case 9:mapp9();break;
	}
	
	init_map();  
	while(1)
	{
		update_food();
	
		get_speed();  
		move_snake();  
		Sleep(snake.speed);
	
		if(is_alive()==2)
		{
			printf("你咬到了自己！");
			break;
		}
			
		if(is_alive()==3)
		{
			printf("你撞墙了！");
			break;
		}
		
		Pos(10,45);
		printf("你的得分为%d",score);
		
	}
	Sleep(2000);
	system("cls");
	gotoxy(25,25);
	color(4);
	printf("你太菜了，Game Over!         \n");
	printf("                 你的最终得分为%d",score);
	
	
	
	getch();
	
	
	return 0;
}
	//initialize
	

void Start_Game()//开始界面
{
    Pos(40, 12);

    system("title 赵心博的寒假作业");
    printf("欢迎来到symbol贪吃蛇游戏！\n");
    Pos(40, 25);
    printf(" 实在是凑不出1000行代码  ");
    system("pause");
    system("cls");
    Pos(25, 12);
    printf("用w.a.s.d分别控制蛇的移动，蛇吃的越多速度越快\n");
    Pos(25, 13);
   // printf("加速将能得到更高的分数。\n");
    system("pause");
    system("cls");
}


void back(void)
{
	int x;
	printf("返回请输入0"); 
	scanf("%d",&x);
	if(x==0)
	{
		system("cls");
		gotoxy(20,20);
	printf("请选择地图"); 
	scanf("%d",&t);
		
	}
	
	
}



void color(short x)    
{  
    if(x>=0 && x<=15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);     
    else 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
} 
	
	
	
void colors(void)
{
	
	u:Pos(25, 12);
	printf("背景颜色说明：请输入一个2到61内的数字。从2开始每6个相邻的数字选择的背景色相同\n9个背景色分别为黑，蓝，绿，湖绿，红，紫，黄，百，灰，淡蓝\n从2开始每相邻6个数字相应颜色为淡绿，浅绿，淡红，淡紫，淡黄，亮白\n"); 
	printf("请选择背景颜色");
	int a;
	scanf("%d",&a);uu=a;
	getchar();
	switch(a)
	{
	case 2:  system("color 0A");break;
	case 3:  system("color 0B");break;
	case 4:  system("color 0C");break;
	case 5:  system("color 0D");break;
	case 6:  system("color 0E");break;
	case 7:  system("color 0F");break;
	case 8:  system("color 1A");break;
	case 9:  system("color 1B");break;
	case 10:  system("color 1C");break;
	case 11:  system("color 1D");break;
	case 12:  system("color 1E");break;
	case 13:  system("color 1F");break;
	case 14:  system("color 2A");break;
	case 15:  system("color 2B");break;
	case 16:  system("color 2C");break;
	case 17:  system("color 2D");break;
	case 18:  system("color 2E");break;
	case 19:  system("color 2F");break;
	case 20:  system("color 3A");break;
	case 21:  system("color 3B");break;
	case 22:  system("color 3C");break;
	case 23:  system("color 3D");break;
	case 24:  system("color 3E");break;
	case 25:  system("color 3F");break;
	case 26:  system("color 4A");break;
	case 27:  system("color 4B");break;
	case 28:  system("color 4C");break;
	case 29:  system("color 4D");break;
	case 30:  system("color 4E");break;
	case 31:  system("color 4F");break;
	case 32:  system("color 5A");break;
	case 33:  system("color 5B");break;
	case 34:  system("color 5C");break;
	case 35:  system("color 5D");break;
	case 36:  system("color 5E");break;
	case 37:  system("color 5F");break;
	case 38:  system("color 6A");break;
	case 39:  system("color 6B");break;
	case 40:  system("color 6C");break;
	case 41:  system("color 6D");break;
	case 42:  system("color 6E");break;
	case 43:  system("color 6F");break;
	case 44:  system("color 7A");break;
	case 45:  system("color 7B");break;
	case 46:  system("color 7C");break;
	case 47:  system("color 7D");break;
	case 48:  system("color 7E");break;
	case 49:  system("color 7F");break;
	case 50:  system("color 8A");break;
	case 51:  system("color 8B");break;
	case 52:  system("color 8C");break;
	case 53:  system("color 8D");break;
	case 54:  system("color 8E");break;
	case 55:  system("color 8F");break;
	case 56:  system("color 9A");break;
	case 57:  system("color 9B");break;
	case 58:  system("color 9C");break;
	case 59:  system("color 9D");break;
	case 60:  system("color 9E");break;
	case 61:  system("color 9F");break;
	
		default:
		{
			printf("没有该颜色组合！\n");
			goto u;
			break;
		} 
	}

	system("CLS");
	
}

void init_map(void)
{
	//初始食物

	o:	srand(time(NULL));
	food.x=rand()%(height-2)+1;
	food.y=rand()%(wide-2)+1;
	gotoxy(food.x, food.y);
	if(map[food.x][food.y]=='#')
	{
		
		goto o;
	}
	printf("*");
	
	
	//initial snake
	snake.x[0]=height/2+15;
	snake.y[0]=wide/2+15;
	gotoxy(snake.x[0], snake.y[0]);
	printf("@");
	snake.len=3;
	snake.speed=200;
	for(k=1;k<snake.len;k++)
	{
		snake.x[k]=snake.x[k-1]+1;
		snake.y[k]=snake.y[k-1];
		gotoxy(snake.x[k], snake.y[k]);
		printf("@");
	}
	//initial bar

	
	
	
//	for(k=5;k<height-7;k++)
//	{
//		gotoxy(k,3);
//		printf("#");
//	}



}


void mapp0(void)
{
	
	Pos(50,50); 
	printf("该地图为无限地图！"); 
	
	for(j=0;j<wide;j++)
	{
		gotoxy(0, j);
		map[0][j]='$';
		printf("$");
		gotoxy(height-1, j);
		map[height-1][j]='$';
		printf("$");
	}
	for(i=1;i<height-1;i++)
	{
		gotoxy(i, 0);
		map[i][0]='$';
		printf("$");
		gotoxy(i, wide-1);
		map[i][wide-1]='$';
		printf("$");
	}
	
	for(i=0;i<=5;i++)
	{
		gotoxy(15-i,15+i);
		map[15-i][15+i]='$';
		printf("$");
		gotoxy(30-i,20+i);
		map[30-i][20+i]='$';
		printf("$");
		gotoxy(20-i,20+i);
		map[15-i][15+i]='$';
		printf("$");
		gotoxy(25-i,15+i);
		map[25-i][15+i]='$';
		printf("$");
		
		gotoxy(20+i,10+i);
		map[20+i][10+i]='$';
		printf("$");
		gotoxy(15+i,25+i);
		map[15+i][25+i]='$';
		printf("$");
		gotoxy(15+i,15+i);
		map[15+i][15+i]='$';
		printf("$");
		gotoxy(20+i,20+i);
		map[20+i][20+i]='$';
		printf("$");
		
	}
	

	
	
	
	
	
}


void mapp1(void)
{
	for(j=0;j<wide;j++)
	{
		gotoxy(0, j);
		map[0][j]='#';
		printf("#");
		gotoxy(height-1, j);
		map[height-1][j]='#';
		printf("#");
	}
	for(i=1;i<height-1;i++)
	{
		gotoxy(i, 0);
		map[i][0]='#';
		printf("#");
		gotoxy(i, wide-1);
		map[i][wide-1]='#';
		printf("#");
	}
}
	
	
void mapp2(void)
{
	

	for(j=0;j<wide;j++)
	{
		gotoxy(0, j);
		printf("#");
		map[0][j]='#';
		gotoxy(height-1, j);
		map[height-1][j]='#';
		printf("#");
	}
	for(i=1;i<height-1;i++)
	{
		gotoxy(i, 0);
		map[i][0]='#';
		printf("#");
		gotoxy(i, wide-1);
		map[i][wide-1]='#';
		printf("#");
	}
	
	for(k=5;k<height-6;k++)
	{
		gotoxy(3,k);
		map[3][k]='#';
		printf("#");
		gotoxy(k+2,4);
		map[k+2][4]='#'; 
		printf("#");
		
	
	}
	    gotoxy(15,15);
		printf("#");
		map[15][15]='#';
		gotoxy(15,16);
		printf("#");
		map[15][16]='#';
		gotoxy(14,15);
		printf("#");
		map[14][15]='#';
}	
	

void mapp3(void)
{
	

	for(j=0;j<wide;j++)
	{
		gotoxy(0, j);
		printf("#");
		map[0][j]='#';
		gotoxy(height-1, j);
		map[height-1][j]='#';
		printf("#");
	}
	for(i=1;i<height-1;i++)
	{
		gotoxy(i, 0);
		map[i][0]='#';
		printf("#");
		gotoxy(i, wide-1);
		map[i][wide-1]='#';
		printf("#");
	}
	
	for(k=20;k<32;k++)
	{
		gotoxy(k,7);
		map[k][7]='#';
		printf("#");
		gotoxy(k-11,17);
		map[k-11][17]='#'; 
		printf("#");
		
	}
	
		for(k=7;k<18;k++)
	{
		gotoxy(20,k);
		map[20][k]='#';
		printf("#");
	
	}
	
	for(k=15;k<26;k++)
	{
		gotoxy(k,12);
		map[k][12]='#';
		printf("#");
	
	}
	for(k=12;k<19;k++)
	{
		gotoxy(26,k);
		map[26][k]='#';
		printf("#");
		gotoxy(15,k-5);
		map[15][k-5]='#'; 
		printf("#");
		
	}
	    
}	



void mapp4(void)
{
	

	for(j=0;j<wide;j++)
	{
		gotoxy(0, j);
		printf("#");
		map[0][j]='#';
		gotoxy(height-1, j);
		map[height-1][j]='#';
		printf("#");
	}
	for(i=1;i<height-1;i++)
	{
		gotoxy(i, 0);
		map[i][0]='#';
		printf("#");
		gotoxy(i, wide-1);
		map[i][wide-1]='#';
		printf("#");
	}
	
	for(i=5;i<19;i++)
	{
		gotoxy(i+3,i+5);
		map[i+3][i+5]='#';
		printf("#");
		gotoxy(25-i,i+3);
		map[25-i][i+3]='#';
		printf("#");
		
	}
	

}	

void mapp5(void)
{
	

	for(j=0;j<wide;j++)
	{
		gotoxy(0, j);
		printf("#");
		map[0][j]='#';
		gotoxy(height-1, j);
		map[height-1][j]='#';
		printf("#");
	}
	for(i=1;i<height-1;i++)
	{
		gotoxy(i, 0);
		map[i][0]='#';
		printf("#");
		gotoxy(i, wide-1);
		map[i][wide-1]='#';
		printf("#");
	}
	
	for(k=5;k<=15;k++)
	{
		gotoxy(k,5);
		map[k][5]='#';
		printf("#");
		gotoxy(k,25);
		map[k][25]='#'; 
		printf("#");
		
		gotoxy(k+15,5);
		map[k+15][5]='#';
		printf("#");
		gotoxy(k+15,25);
		map[k+15][25]='#'; 
		printf("#");
	
	}
	    
	  for(k=5;k<=10;k++)
	{
		gotoxy(15,k);
		map[15][k]='#';
		printf("#");
		gotoxy(20,k);
		map[20][k]='#';
		printf("#");
		
		gotoxy(15,k+15);
		map[15][k+15]='#';
		printf("#");
		gotoxy(20,k+15);
		map[20][k+15]='#';
		printf("#");
	
	}  
	    
}	
	

void mapp6(void)
{
	

	for(j=0;j<wide;j++)
	{
		gotoxy(0, j);
		printf("#");
		map[0][j]='#';
		gotoxy(height-1, j);
		map[height-1][j]='#';
		printf("#");
	}
	for(i=1;i<height-1;i++)
	{
		gotoxy(i, 0);
		map[i][0]='#';
		printf("#");
		gotoxy(i, wide-1);
		map[i][wide-1]='#';
		printf("#");
	}
	
	for(k=5;k<=15;k++)
	{
		gotoxy(k,10);
		map[k][10]='#';
		printf("#");
		gotoxy(k,20);
		map[k][20]='#'; 
		printf("#");
		
		gotoxy(k+15,10);
		map[k+15][10]='#';
		printf("#");
		gotoxy(k+15,20);
		map[k+15][20]='#'; 
		printf("#");
	
	}
	    
	  for(k=5;k<=10;k++)
	{
		gotoxy(15,k);
		map[15][k]='#';
		printf("#");
		gotoxy(20,k);
		map[20][k]='#';
		printf("#");
		
		gotoxy(15,k+15);
		map[15][k+15]='#';
		printf("#");
		gotoxy(20,k+15);
		map[20][k+15]='#';
		printf("#");
	
	}  
	    
}	


void mapp7(void)
{
	

	for(j=0;j<wide;j++)
	{
		gotoxy(0, j);
		printf("#");
		map[0][j]='#';
		gotoxy(height-1, j);
		map[height-1][j]='#';
		printf("#");
	}
	for(i=1;i<height-1;i++)
	{
		gotoxy(i, 0);
		map[i][0]='#';
		printf("#");
		gotoxy(i, wide-1);
		map[i][wide-1]='#';
		printf("#");
	}
	
	for(k=10;k<=20;k++)
	{
		gotoxy(25-k,k);
		map[25-k][k]='#';
		printf("#");
		gotoxy(40-k,k+15);
		map[40-k][k+15]='#'; 
		printf("#");
		
		gotoxy(k-5,k+14);
		map[k-5][k+14]='#';
		printf("#");
		gotoxy(k+10,k);
		map[k+10][k]='#'; 
		printf("#");
	
	}
	    
 		gotoxy(20,20);
		map[20][20]='$'; 
		printf("$");
	    
}	



void mapp8(void)
{
	

	for(j=0;j<wide;j++)
	{
		gotoxy(0, j);
		printf("#");
		map[0][j]='#';
		gotoxy(height-1, j);
		map[height-1][j]='#';
		printf("#");
	}
	for(i=1;i<height-1;i++)
	{
		gotoxy(i, 0);
		map[i][0]='#';
		printf("#");
		gotoxy(i, wide-1);
		map[i][wide-1]='#';
		printf("#");
	}
	
		gotoxy(4, 4);
		map[4][4]='#';
		printf("#");
		gotoxy(6, 4);
		map[6][4]='#';
		printf("#");
		gotoxy(4, 14);
		map[4][14]='#';
		printf("#");
		gotoxy(5, 5);
		map[5][5]='#';
		printf("#");
		gotoxy(22, 1);
		map[22][1]='#';
		printf("#");
		gotoxy(29, 14);
		map[29][14]='#';
		printf("#");
		gotoxy(13, 17);
		map[16][19]='#';
		printf("#");
		gotoxy(7, 25);
		map[7][25]='#';
		printf("#");
		gotoxy(6, 28);
		map[6][28]='$';
		printf("$");
		gotoxy(9, 19);
		map[9][19]='#';
		printf("#");
		gotoxy(14, 14);
		map[14][14]='$';
		printf("$");
		gotoxy(4, 4);
		map[4][4]='#';
		printf("#");
		gotoxy(4, 2);
		map[4][2]='#';
		printf("#");
		gotoxy(14, 13);
		map[14][13]='#';
		printf("#");
		gotoxy(5, 5);
		map[5][5]='#';
		printf("#");
		gotoxy(4, 22);
		map[4][22]='#';
		printf("#");
		gotoxy(4, 7);
		map[4][7]='#';
		printf("#");
		gotoxy(7, 4);
		map[7][4]='#';
		printf("#");
	
	
	    
}	


void mapp9(void)
{
	

	for(j=0;j<wide;j++)
	{
		gotoxy(0, j);
		printf("#");
		map[0][j]='#';
		gotoxy(height-1, j);
		map[height-1][j]='#';
		printf("#");
	}
	for(i=1;i<height-1;i++)
	{
		gotoxy(i, 0);
		map[i][0]='#';
		printf("#");
		gotoxy(i, wide-1);
		map[i][wide-1]='#';
		printf("#");
	}
	
	for(i=0;i<=5;i++)
	{
		gotoxy(15-i,15+i);
		map[15-i][15+i]='#';
		printf("#");
		gotoxy(30-i,20+i);
		map[30-i][20+i]='#';
		printf("#");
		gotoxy(20-i,20+i);
		map[15-i][15+i]='#';
		printf("#");
		gotoxy(25-i,15+i);
		map[25-i][15+i]='#';
		printf("#");
		
		gotoxy(20+i,10+i);
		map[20+i][10+i]='#';
		printf("#");
		gotoxy(15+i,25+i);
		map[15+i][25+i]='#';
		printf("#");
		gotoxy(15+i,15+i);
		map[15+i][15+i]='#';
		printf("#");
		gotoxy(20+i,20+i);
		map[20+i][20+i]='#';
		printf("#");
		
	}
	

}	




	//generate food
void update_food()
{
	if(snake.x[0]==food.x&&snake.y[0]==food.y)
	{
		
		
		f:	srand(time(NULL));
		food.x=rand()%(height-2)+1;
		food.y=rand()%(wide-2)+1;
		gotoxy(food.x, food.y);
		if(map[food.x][food.y]==' ')
		{
			
			goto f;
		}
		
		printf("*");
		
		
		
		snake.len++;
		score+=10;
		grow=1;
		
		if(map[snake.x[0]][snake.y[0]]=='$')
	{
		score+=20;
		snake.len+=1;
		grow=1;
		snake.speed=220;
	}
		
	}
}
	//move snake
	
void move_snake()
{
	if(kbhit())
	{
		ch=getch();
	}
	
	if(!grow)
	{
		gotoxy(snake.x[snake.len-1], snake.y[snake.len-1]);
		printf(" ");
	}
	
	for(k=snake.len-1;k>0;k--)
	{
		snake.x[k]=snake.x[k-1];
		snake.y[k]=snake.y[k-1];
	}
	
	switch(ch)
	{
		case UP:  snake.x[0]--;break;
		case DOWN:  snake.x[0]++;break;
		case LEFT:  snake.y[0]--;break;
		case RIGHT:  snake.y[0]++;break;
		case ' ':
		{
			
			system("pause");
			Pos(40,40);
			printf("按回车继续");
			 
			break;
			
		}
		case '\n':
		{
			
			
			break;
			
		}
	//default:  break;
	}
	gotoxy(snake.x[0], snake.y[0]);
	
	if(map[snake.x[0]][snake.y[0]]=='#')
	{
		snake.x[0]==0;
		goto c;
		
	}
	
	printf("@");
	grow=0;
c:	gotoxy(height, 0);
}
	//is alive
int is_alive(void)
{
//	if(snake.x[0]==0||snake.x[0]==height-1||snake.y[0]==wide-1||snake.y[0]==0)
//	{
//		return 3;
//	}
	
	if(map[snake.x[0]][snake.y[0]]=='#')
	{
		return 3;
	}
	

	
	for(k=1;k<snake.len;k++)
	{
		if(snake.x[k]==snake.x[0]&&snake.y[k]==snake.y[0])
		{
			return 2;
		}
	}
	
	
	return 1;
}
	//speed up
void get_speed(void)
{
	if(snake.len<=6)
	{
		snake.speed=200;
	}
	
	else if(snake.len<=10)
	{
		snake.speed=100;
	}
	
	else if(snake.len<=20)
	{
		snake.speed=50;
	}
	
	else if(snake.len<=30)
	{
		snake.speed=30;
	}
	
	else 
	{
		snake.speed=20;	
	}
}
	//move cursor
void gotoxy(int x, int y)//光标移动 
{
	HANDLE hout;
	COORD cor;
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	cor.X=y;
	cor.Y=x;
	SetConsoleCursorPosition(hout,cor);
}
	

