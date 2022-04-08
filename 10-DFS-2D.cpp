#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 100;
bool visted[N][N];

bool isValid(int x, int y, int n, int m)
{
    if (x < 1 || x > n || y < 1 || y > m || visted[x][y])
        return false;

    return true;
}

// Direction in X-axis,Y-axis (Acc.to.Problem)
vector<int> dx{-1, 0, 1, 0};
vector<int> dy{0, 1, 0, -1};

void dfs(int x, int y, int n, int m)
{

    cout << x << " " << y << endl;
    visted[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (isValid(X, Y, n, m))
        {
            dfs(X, Y, n, m);
        }
    }
}

// Problem1 : https://codeforces.com/contest/723/problem/D
// Solution : https://codeforces.com/contest/723/submission/153001292