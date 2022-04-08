#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e6;
vector<int> adj[N];
bool visted[N];

void dfs(int node)
{

    visted[node] = true;
    for (auto it : adj[node])
    {
        if (!visted[it])
            dfs(it);
    }
}

// Problem 1 : https://codeforces.com/contest/977/problem/E
// Solution  : https://codeforces.com/contest/977/submission/152987238
