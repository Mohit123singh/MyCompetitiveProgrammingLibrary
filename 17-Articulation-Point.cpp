#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
int n, m, timer;
int low[N], in[N];
bool visted[N];
set<int> articulation_point;

int dfs(int node, int par = -1)
{
    visted[node] = true;
    low[node] = in[node] = timer++;
    int children = 0;
    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        if (visted[child])
            low[node] = min(low[node], in[child]);
        else
        {
            dfs(child, node);

            if (low[child] >= in[node] && par != -1)
                articulation_point.insert(node);

            low[node] = min(low[node], low[child]);
            children++;
        }
    }
    if (par == -1 && children > 1)
        articulation_point.insert(node);

    return articulation_point.size();
}

// Problem 1 : https://www.spoj.com/problems/SUBMERGE/
// Solution1 : https://ideone.com/WHJiap
