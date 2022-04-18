#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1500;
int dp[N][21], level[N];
vector<int> adj[N];

void dfs(int node, int p = -1, int d = 0)
{
    level[node] = d;
    dp[node][0] = p;

    for (auto it : adj[node])
    {
        if (it != p)
            dfs(it, node, d + 1);
    }
}
void init(int n)
{
    for (int i = 0; i <= 19; i++)
    {
        for (int node = 1; node <= n; node++)
            dp[node][i] = -1;
    }

    dfs(1);

    for (int i = 1; i <= 19; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            int p = dp[node][i - 1];
            if (p != -1)
                dp[node][i] = dp[p][i - 1];
        }
    }
}

// kth-Ancestor
int kthAncestor(int node, int k)
{
    for (int i = 24; i >= 0; i--)
    {
        int d = ((int)1 << i);

        if (d <= k)
        {
            node = dp[node][i];
            k -= d;
        }
    }
    return node;
}

int find_LCA(int a, int b)
{
    if (level[a] > level[b])
        swap(a, b);

    int d = level[b] - level[a];

    while (d > 0)
    {
        int i = log2(d);
        b = dp[b][i];
        d -= ((int)1 << i);
    }
    if (a == b)
        return a;

    for (int i = 19; i >= 0; i--)
    {
        if (dp[b][i] != -1 and dp[b][i] != dp[a][i])
        {
            b = dp[b][i];
            a = dp[a][i];
        }
    }
    return dp[a][0];
}

// Problem1 : https://www.spoj.com/problems/LCA/
// Solution : https://ideone.com/FHTugb
