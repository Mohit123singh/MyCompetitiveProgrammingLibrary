#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

class edge
{
public:
    int u, v, w;
    edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

const int N = 1e6;
vector<edge> e;
int n, m, last_node;
int dist[N], par[N];

bool is_negative_cycle(int src)
{
    bool f = false;
    dist[src] = 0;
    par[src] = src;
    for (int i = 1; i <= n; i++)
    {
        f = false;

        for (auto edg : e)
        {
            int u = edg.u;
            int v = edg.v;
            int w = edg.w;

            if (dist[v] > dist[u] + w)
            {
                f = true;
                dist[v] = dist[u] + w;
                par[v] = u;
                last_node = v;
            }
        }
    }
    return f;
}

void print_negative_cycle_nodes()
{
    for (int i = 1; i <= n; i++)
    {
        last_node = par[last_node];
    }

    int node = last_node;

    vector<int> cycle_nodes;

    while (true)
    {
        cycle_nodes.push_back(node);
        if (cycle_nodes.size() > 1 and node == last_node)
            break;
        node = par[node];
    }
    reverse(cycle_nodes.begin(), cycle_nodes.end());

    for (auto it : cycle_nodes)
        cout << it << " ";
}

// Problem1 : https://cses.fi/problemset/task/1197/
// Solution : https://cses.fi/paste/2f5ae9d015bcb1ef3a5a37/
