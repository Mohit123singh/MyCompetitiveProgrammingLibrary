#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e6;
vector<int> adj[N];
bool visted[N];
bool dfs(int node, int p = -1)
{
    visted[node] = true;
    for (auto it : adj[node])
    {
        if (!visted[it])
        {
            if (dfs(it, node))
                return true;
        }
        else if (p != it)
            return true;
    }
    return false;
}

// Problem 1 : https://cses.fi/problemset/task/1669
// Solution  : https://cses.fi/paste/aa1243ccfae4ae333a0795/
