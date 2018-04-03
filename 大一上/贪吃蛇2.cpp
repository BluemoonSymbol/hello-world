#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>

#define U 1
#define D 2
#define L 3 
#define R 4       //????,U:? ;D:?;L:? R:?

typedef struct SNAKE //???????
{
    int x;
    int y;
    struct SNAKE *next;
}snake;

//????//
int score = 0, add = 10;//????????????
int status, sleeptime = 200;//?????????
snake *head, *food;//????,????
snake *q;//???????????
int endGamestatus = 0; //???????,1:???;2:????;3:???????

//??????//
void Pos();
void creatMap();
void initSnake();
int biteSelf();
void createFood();
void cantCrossWall();
void snakeMove();
void pause();
void runGame();
void initGame();
void endGame();
void gameStart();

void Pos(int x, int y)//??????
{
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//???????????????????,??????????/???????????
    SetConsoleCursorPosition(hOutput, pos);
}

void creatMap()//????
{
    int i;
    for (i = 0; i<58; i += 2)//??????
    {
        Pos(i, 0);
        printf("¦");//?????????
        Pos(i, 26);
        printf("¦");
    }
    for (i = 1; i<26; i++)//??????
    {
        Pos(0, i);
        printf("¦");
        Pos(56, i);
        printf("¦");
    }
}

void initSnake()//?????
{
    snake *tail;
    int i;
    tail = (snake*)malloc(sizeof(snake));//?????,???,?x,y???????//
    tail->x = 24;
    tail->y = 5;
    tail->next = NULL;
    for (i = 1; i <= 4; i++)//?????4
    {
        head = (snake*)malloc(sizeof(snake));
        head->next = tail;
        head->x = 24 + 2 * i;
        head->y = 5;
        tail = head;
    }
    while (tail != NULL)//????,????
    {
        Pos(tail->x, tail->y);
        printf("¦");
        tail = tail->next;
    }
}
//??
int biteSelf()//?????????
{
    snake *self;
    self = head->next;
    while (self != NULL)
    {
        if (self->x == head->x && self->y == head->y)
        {
            return 1;
        } 
        self = self->next;
    }
    return 0;
}

void createFood()//??????
{
    snake *food_1;
    srand((unsigned)time(NULL));//??????????????,?????time
    food_1 = (snake*)malloc(sizeof(snake));
    while ((food_1->x % 2) != 0)    //??????,??????????
    {
        food_1->x = rand() % 52 + 2;
    }
    food_1->y = rand() % 24 + 1;
    q = head;
    while (q->next == NULL)
    {
        if (q->x == food_1->x && q->y == food_1->y) //???????????
        {
            free(food_1);
            createFood();
        }
        q = q->next;
    }
    Pos(food_1->x, food_1->y);
    food = food_1;
    printf("¦");
}

void cantCrossWall()//????
{
    if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)
    {
        endGamestatus = 1;
        endGame();
    }
}

void snakeMove()//???,?U,?D,?L,?R
{
    snake * nexthead;
    cantCrossWall();

    nexthead = (snake*)malloc(sizeof(snake));
    if (status == U)
    {
        nexthead->x = head->x;
        nexthead->y = head->y - 1;
        if (nexthead->x == food->x && nexthead->y == food->y)//????????//
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q != NULL)
            {
                Pos(q->x, q->y);
                printf("¦");
                q = q->next;
            }
            score = score + add;
            createFood();
        }
        else                                               //??????//
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q->next->next != NULL)
            {
                Pos(q->x, q->y);
                printf("¦");
                q = q->next;
            }
            Pos(q->next->x, q->next->y);
            printf("  ");
            free(q->next);
            q->next = NULL;
        }
    }
    if (status == D)
    {
        nexthead->x = head->x;
        nexthead->y = head->y + 1;
        if (nexthead->x == food->x && nexthead->y == food->y)  //???
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q != NULL)
            {
                Pos(q->x, q->y);
                printf("¦");
                q = q->next;
            }
            score = score + add;
            createFood();
        }
        else                               //????
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q->next->next != NULL)
            {
                Pos(q->x, q->y);
                printf("¦");
                q = q->next;
            }
            Pos(q->next->x, q->next->y);
            printf("  ");
            free(q->next);
            q->next = NULL;
        }
    }
    if (status == L)
    {
        nexthead->x = head->x - 2;
        nexthead->y = head->y;
        if (nexthead->x == food->x && nexthead->y == food->y)//???
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q != NULL)
            {
                Pos(q->x, q->y);
                printf("¦");
                q = q->next;
            }
            score = score + add;
            createFood();
        }
        else                                //????
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q->next->next != NULL)
            {
                Pos(q->x, q->y);
                printf("¦");
                q = q->next;
            }
            Pos(q->next->x, q->next->y);
            printf("  ");
            free(q->next);
            q->next = NULL;
        }
    }
    if (status == R)
    {
        nexthead->x = head->x + 2;
        nexthead->y = head->y;
        if (nexthead->x == food->x && nexthead->y == food->y)//???
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q != NULL)
            {
                Pos(q->x, q->y);
                printf("¦");
                q = q->next;
            }
            score = score + add;
            createFood();
        }
        else                                         //????
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q->next->next != NULL)
            {
                Pos(q->x, q->y);
                printf("¦");
                q = q->next;
            }
            Pos(q->next->x, q->next->y);
            printf("  ");
            free(q->next);
            q->next = NULL;
        }
    }
    if (biteSelf() == 1)       //?????????
    {
        endGamestatus = 2;
        endGame();
    }
}

void pause()//??
{
    while (1)
    {
        Sleep(300);
        if (GetAsyncKeyState(VK_SPACE))
        {
            break;
        }

    }
}

void runGame()//????        
{

    Pos(64, 15);
    printf("????,??????\n");
    Pos(64, 16);
    printf("??.?.?.?????????.");
    Pos(64, 17);
    printf("F1 ???,F2 ???\n");
    Pos(64, 18);
    printf("ESC :????.space:????.");
    Pos(64, 20);
    printf("C?????? www.clang.cc");
    status = R;
    while (1)
    {
        Pos(64, 10);
        printf("??:%d  ", score);
        Pos(64, 11);
        printf("??????:%d?", add);
        if (GetAsyncKeyState(VK_UP) && status != D)
        {
            status = U;
        }
        else if (GetAsyncKeyState(VK_DOWN) && status != U)
        {
            status = D;
        }
        else if (GetAsyncKeyState(VK_LEFT) && status != R)
        {
            status = L;
        }
        else if (GetAsyncKeyState(VK_RIGHT) && status != L)
        {
            status = R;
        }
        else if (GetAsyncKeyState(VK_SPACE))
        {
            pause();
        }
        else if (GetAsyncKeyState(VK_ESCAPE))
        {
            endGamestatus = 3;
            break;
        }
        else if (GetAsyncKeyState(VK_F1))
        {
            if (sleeptime >= 50)
            {
                sleeptime = sleeptime - 30;
                add = add + 2;
                if (sleeptime == 320)
                {
                    add = 2;//????1????????
                }
            }
        }
        else if (GetAsyncKeyState(VK_F2))
        {
            if (sleeptime<350)
            {
                sleeptime = sleeptime + 30;
                add = add - 2;
                if (sleeptime == 350)
                {
                    add = 1;  //??????1
                }
            }
        }
        Sleep(sleeptime);
        snakeMove();
    }
}

void initGame()//????
{
    Pos(40, 12);

    system("title C??????   www.clang.cc");
    printf("?????????!");
    Pos(40, 25);
    printf("              C??????  www.clang.cc.\n");
    system("pause");
    system("cls");
    Pos(25, 12);
    printf("??.?.?.?????????, F1 ???,2 ???\n");
    Pos(25, 13);
    printf("????????????\n");
    system("pause");
    system("cls");
}

void endGame()//????
{

    system("cls");
    Pos(24, 12);
    if (endGamestatus == 1)
    {
        printf("???,??????????.");
    }
    else if (endGamestatus == 2)
    {
        printf("???,???????????.");
    }
    else if (endGamestatus == 3)
    {
        printf("??????????");
    }
    Pos(24, 13);
    printf("?????%d\n", score);
    while (getchar() != 'y')
    {    
        printf("close?[y]");
    }
    exit(0);
}

void gameStart()//?????
{
    system("mode con cols=100 lines=30");
    initGame();
    creatMap();
    initSnake();
    createFood();
}

int main()
{
    gameStart();
    runGame();
    endGame();
    return 0;
}
