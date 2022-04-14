#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

// floyd warshall algo::
// It is used to find  the shortest path of every u-v;

int dist[500][500];
int n;
void FloydWarshall()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

// Problem1 : https://codeforces.com/problemset/problem/25/C
// Solution : https://codeforces.com/contest/25/submission/153491389

// Problem2 : https://codeforces.com/contest/33/problem/B
// Solution : https://codeforces.com/contest/33/submission/153554422
