
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e6;
vector<pair<int, int>> adj[N];
int par[N], dist[N], cost;
bool mst[N];
vector<pair<int, int>> MST_edges;

int prism(int src, int n)
{
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, src});

    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        // cycle
        if (mst[u])
            continue;
        mst[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (!mst[v] and dist[v] > w)
            {
                par[v] = u;
                dist[v] = w;
                q.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (par[i])
            MST_edges.push_back({i, par[i]});
        cost += dist[i];
    }

    return cost;
}

// Problem 1 : https://cses.fi/problemset/task/1675
// Solution  : https://cses.fi/paste/0438e9e3c79f35d13a774d/
