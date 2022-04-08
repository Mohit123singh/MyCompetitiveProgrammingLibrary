#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e6;
vector<int> adj[N];
bool visted[N];
int disc[N], low[N];
int timer;
vector<pair<int, int>> bridges;

void dfs(int node, int par)
{
    low[node] = disc[node] = timer;
    timer++;
    visted[node] = true;

    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        ;
        if (visted[child])
        {
            // there is a back edge from child to node:
            low[node] = min(disc[child], low[node]);
        }
        else
        {
            // there is a forward edge from child to node::

            dfs(child, node);

            if (low[child] > disc[node])
                bridges.push_back({node, child});
            low[node] = min(low[node], low[child]);
        }
    }
}

// Problem 1 : https://www.spoj.com/problems/EC_P/
// Solution  : https://ideone.com/lqrkh4
