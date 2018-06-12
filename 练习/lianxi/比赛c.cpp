#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct Matrix
{
    unsigned long long m[9][9];
} I, A, T;

Matrix matrixmul(Matrix a, Matrix b)
{
    unsigned long long i, j, k;
    Matrix c;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            c.m[i][j] = 0;

    for (i = 0; i < 9; i++)
        for (k = 0; k < 9; k++)
        {
            if (a.m[i][k] != 0)
                for (j = 0; j < 9; j++)
                {
                    c.m[i][j] += (a.m[i][k] * b.m[k][j]);
                }
        }
    return c;
}

Matrix quickpagow(unsigned long long tt)
{
    Matrix m = A, b = I;
    while (tt >= 1)
    {
        if (tt & 1)
            b = matrixmul(b, m);
        tt = tt >> 1;
        m = matrixmul(m, m);
    }
    return b;
}

unsigned long long TT, n;

int main()
{
    cin >> TT;
    memset(I.m, 0, sizeof(I.m));
    memset(A.m, 0, sizeof(A.m));
    for (unsigned long long i = 0; i < 9; i++)
    {
        I.m[i][i] = 1;
    }

    for (unsigned long long i = 0; i < 9; i++)
    {
        for (unsigned long long j = 0; j < 9 - i; j++)
        {
            A.m[j][i] = 1;
        }
    }
    while (TT--)
    {
        scanf("%llu", &n);
        T = quickpagow(n - 2);
        unsigned long long anss = 0;
        unsigned long long vv[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        for (unsigned long long i = 0; i < 9; i++)
        {
            for (unsigned long long j = 0; j < 9; j++)
            {
                anss += vv[j] * T.m[i][j];
            }
        }
        printf("%llu\n", anss);
    }
    return 0;
}

