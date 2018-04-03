#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>


int MAP[4][4],gre;


int add(int n)
{
srand((unsigned int)time(0));
int num = rand();
int tf = num % 2;
int x,y,i;
x = num % 4;
srand((unsigned int)time(0) + (unsigned int)num);
y = rand();
y %= 4;
if (tf)
num = 2;
else
num = 4;


if (n == 0)
{
MAP[x][y] = num;
}
else if (n == 1)
{
if (MAP[3][y] == 0)
MAP[3][y] = num;
else
for (i = 0; i < 4; i++)
if (MAP[3][i] == 0)
{
MAP[3][i] = num;
break;
}
}
else if (n == 2)
{
if (MAP[0][y] == 0)
MAP[0][y] = num;
else
for (i = 0; i < 4; i++)
if (MAP[0][i] == 0)
{
MAP[0][i] = num;
break;
}
}
else if (n == 3)
{
if (MAP[x][3] == 0)
MAP[x][3] = num;
else
for (i = 0; i < 4; i++)
if (MAP[i][3] == 0)
{
MAP[i][3] = num;
break;
}
}
else if (n == 4)
{
if (MAP[x][0] == 0)
MAP[x][0] = num;
else
for (i = 0; i < 4; i++)
if (MAP[i][0] == 0)
{
MAP[i][0] = num;
break;
}
}
}


int movup(void)
{
int i,k,t;
int tf = 0;
for (k = 0; k < 4; k++)
{
int n = 4;
while (n--)
for (i = 0; i < 3; i++)
if (MAP[i][k] == 0)
{
for (t = i; t < 3; t++)
{
MAP[t][k] = MAP[t + 1][k];
MAP[t + 1][k] = 0;
tf = 1;
}
}
for (i = 0; i < 3; i++)
{
if (MAP[i][k] == MAP[i + 1][k])
{
MAP[i][k] *= 2;
gre += MAP[i][k];
if (MAP[i][k] == 2048)
return 0;
for (t = i + 1; t < 3; t++)
{
MAP[t][k] = MAP[t + 1][k];
MAP[t + 1][k] = 0;
tf = 1;
}
}
}
}
if (tf)
add(1);
return 1;
}

int movdow(void)
{
int i,k,t;
int tf = 0;
for (k = 0; k < 4; k++)
{
int n = 4;
while (n--)
for (i = 3; i > 0; i--)
if (MAP[i][k] == 0)
{
for (t = i; t > 0; t--)
{
MAP[t][k] = MAP[t - 1][k];
MAP[t - 1][k] = 0;
tf = 1;
}
}
for (i = 3; i > 0; i--)
{
if (MAP[i][k] == MAP[i - 1][k])
{
MAP[i][k] *= 2;
gre += MAP[i][k];
if (MAP[i][k] == 2048)
return 0;
for (t = i - 1; t > 0; t--)
{
MAP[t][k] = MAP[t - 1][k];
MAP[t - 1][k] = 0;
tf = 1;
}
}
}
}
if (tf)
add(2);
return 1;
}


int movlif(void)
{
int i,k,t;
for (i = 0; i < 4; i++)
{
int n = 4;
while (n--)
for (k = 0; k < 3; k++)
{
if(MAP[i][k] == 0)
for (t = k; t < 3; t++)
{
MAP[i][t] = MAP[i][t + 1];
MAP[i][t + 1] = 0;
}
}
for (k = 0;k < 3;k++)
{
if (MAP[i][k] == MAP[i][k + 1])
{
MAP[i][k] *= 2;
gre += MAP[i][k];
if (MAP[i][k] == 2048)
return 0;
for (t = k + 1; t < 3; t++)
{
MAP[i][t] = MAP[i][t + 1];
MAP[i][t + 1] = 0;
}
}
}
}
add(3);
return 1;
}


int movri(void)
{
int i,k,t;
for (i = 0; i < 4; i++)
{
int n = 4;
while (n--)
for (k = 3; k > 0; k--)
{
if(MAP[i][k] == 0)
for (t = k; t > 0; t--)
{
MAP[i][t] = MAP[i][t - 1];
MAP[i][t - 1] = 0;
}
}
for (k = 3;k > 0;k--)
{
if (MAP[i][k] == MAP[i][k - 1])
{
MAP[i][k] *= 2;
gre += MAP[i][k];
if (MAP[i][k] == 2048)
return 0;
for (t = k - 1; t > 0; t--)
{
MAP[i][t] = MAP[i][t - 1];
MAP[i][t - 1] = 0;
}
}
}
}
add(4);
return 1;
}
int mov(void)
{
fflush(stdin);
char key;
key = getch();


int tf = 1;


if (key == 72)
tf = movup();
else if (key == 80)
tf = movdow();
else if (key == 75)
tf = movlif();
else if (key == 77)
tf = movri();


if (!tf)
{
system("CLS");
printf ("恭喜达到2048！\n");
}
return tf;
}

int pd (void)
{
int i,k;


for (i = 0; i < 4; i++)
{
for (k = 1; k < 4; k++)
if (MAP[i][k - 1] == MAP[i][k])
return 0;
}


for (i = 0; i < 4; i++)
{
for (k = 1; k < 4; k++)
if (MAP[k - 1][i] == MAP[k][i])
return 0;
}


system("CLS");
printf ("游戏结束！\n");
return 1;
}


int pri (void)
{
printf ("得分：%d\n",gre);
printf ("\t┏━━┳━━┳━━┳━━┓\n");
printf ("\t┃%4d┃%4d┃%4d┃%4d┃\n",MAP[0][0],MAP[0][1],MAP[0][2],MAP[0][3]);
printf ("\t┣━━╋━━╋━━╋━━┫\n");
printf ("\t┃%4d┃%4d┃%4d┃%4d┃\n",MAP[1][0],MAP[1][1],MAP[1][2],MAP[1][3]);
printf ("\t┣━━╋━━╋━━╋━━┫\n");
printf ("\t┃%4d┃%4d┃%4d┃%4d┃\n",MAP[2][0],MAP[2][1],MAP[2][2],MAP[2][3]);
printf ("\t┣━━╋━━╋━━╋━━┫\n");
printf ("\t┃%4d┃%4d┃%4d┃%4d┃\n",MAP[3][0],MAP[3][1],MAP[3][2],MAP[3][3]);
printf ("\t┗━━┻━━┻━━┻━━┛\n");
}


int main()
{
int i;
system("COLOR 5F");


printf ("\n\t【2048】控制台版\n\n");
printf ("游戏规则（如同名手游）：\n");
printf ("\t开始方格内会出现2或者4等这两个小数字，\n");
printf ("\t玩家只需要上下左右（方向键控制）其中一个方向来移动出现的数字，\n");
printf ("\t所有的数字就会向滑动的方向靠拢，\n");
printf ("\t而滑出的空白方块就会随机出现一个数字，\n");
printf ("\t相同的数字相撞时会叠加靠拢，\n");
printf ("\t然后一直这样，不断的叠加最终拼凑出2048这个数字就算成功。\n");
printf ("\n\n!输入任意非零字符开始游戏!\n（建议将控制台设置为大字体）\n");


char s[100];
while (scanf ("%s",s),strcmp(s,"0"))
{
memset (MAP,0,sizeof (MAP));
gre = 0;
system("CLS");
add(0);
pri();
while (mov())
{
fflush(stdin);
system("CLS");
pri();
if (pd())
break;
}


printf ("按任继续游戏！输入0退出程序！\n");
}


return 0;
}


