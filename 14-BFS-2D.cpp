#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

// BFS on 2d grid:::::

const int N = 1e3;
bool visted[N][N];
int dist[N][N];
vector<int> dx{-1, 0, 1, 0};
vector<int> dy{0, 1, 0, -1};

bool isValid(int i, int j, int n, int m)
{
    if (i < 1 || i > n || j < 1 || j > m || visted[i][j])
        return false;
    return true;
}

int bfs(int x, int y, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[{x, y}] = 0;
    visted[x][y] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if (isValid(X, Y, n, m))
            {
                q.push({X, Y});
                visted[X][Y] = true;
                dist[X][Y] = dist[x][y] + 1;
            }
        }
    }
    return dist[n][m];
}

// Problem 1 : https://codeforces.com/contest/877/problem/D
// Solution  : https://codeforces.com/contest/877/submission/153284480

// Multi-source BFS:
// Problem 2 : https://codeforces.com/problemset/problem/35/C
// Solution  : https://codeforces.com/contest/35/submission/153287085
