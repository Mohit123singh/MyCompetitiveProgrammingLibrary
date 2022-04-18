#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e5 + 100;
vector<int> adj[N];

const int N = 1e6;
vector<int> adj[N];
int k = -1, first_node;

void dfs(int node, int p = -1, int d = 0)
{
    if (d > k)
    {
        k = d;
        first_node = node;
    }

    for (auto it : adj[node])
    {
        if (it != p)
            dfs(it, node, d + 1);
    }
}

int find_diameter(int src)
{
    dfs(src);
    k = -1;
    dfs(first_node);
    return k;
}

// Problem1 : https://codeforces.com/gym/102694/problem/A
// Solution : https://codeforces.com/gym/102694/submission/153972590
