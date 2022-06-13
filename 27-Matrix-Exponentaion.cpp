
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int dp[N][N], I[N][N], res[N][N];
int n, m,mod=1e7;

void multiply(int A[][N], int B[][N])
{

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int sum = 0;

            for (int k = 1; k <= m; k++)
                sum = (sum + (A[i][k] * B[k][j]) % mod) % mod;
            res[i][j] = sum;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
            A[i][j] = res[i][j];
    }
}
void matrixPow()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

    while (n)
    {
        if (n % 2 == 0)
        {
            multiply(dp, dp);
            n /= 2;
        }
        else
        {
            multiply(I, dp);
            n--;
        }
    }
}

// Problem1 :  https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem
// Solution : https://ideone.com/8foGmk