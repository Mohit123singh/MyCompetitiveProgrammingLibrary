

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e6;
vector<int> adj[N];
int par[N];
bool visted[N], recVisted[N];
int cycle_node;
bool dfs(int node, int p = -1)
{
    visted[node] = true;
    recVisted[node] = true;
    par[node] = p;
    for (auto it : adj[node])
    {
        if (!visted[it])
        {
            if (dfs(it, node))
                return true;
        }
        else if (recVisted[it])
        {
            cycle_node = it;
            par[it] = node;
            return true;
        }
    }
    recVisted[node] = false;
    return false;
}

// Problem1 : https://cses.fi/problemset/task/1678/
// Solution : https://cses.fi/paste/f0360af42443ba703a0817/