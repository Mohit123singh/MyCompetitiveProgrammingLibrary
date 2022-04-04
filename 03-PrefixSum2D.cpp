#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

// prefix-sum in 2d matrix:

const int N = 100;

int dp[N][N], matrix[N][N];

void create_prefix2d_array(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = matrix[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
}

int get_sum_of_sub_rectange(int r1, int c1, int r2, int c2)
{
    int sum = dp[r2][c2];
    sum -= dp[r1 - 1][c2];
    sum -= dp[r2][c1 - 1];
    sum += dp[r1 - 1][c1 - 1];

    return sum;
}

// Problem 1 : https://codeforces.com/problemset/problem/835/C
// Solution  : https://codeforces.com/contest/835/submission/146096181
