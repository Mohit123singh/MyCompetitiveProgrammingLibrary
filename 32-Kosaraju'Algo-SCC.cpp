#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e6;
vector<int> adj[N], rev[N];
bool visted[N];
stack<int> s;

// Sort nodes acc. to finishing-time(using concept of topo-sort);

void dfs(int node)
{
    visted[node] = true;

    for (auto it : adj[node])
    {
        if (!visted[it])
            dfs(it);
    }
    s.push(node);
}

void dfs1(int node)
{
    visted[node] = true;
    cout << node << " ";
    for (auto it : rev[node])
    {
        if (!visted[it])
            dfs(it);
    }
}

// finding the SCC in directed-Graph:

void find_SCC(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (!visted[i])
            dfs(i);
    }

    memset(visted, false, sizeof(visted));

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (visted[node])
            continue;
        cout << "SCC : " << endl;
        dfs1(node);
        cout << endl;
    }
}

// Problem 1 : https://codeforces.com/contest/427/problem/C
// Solution  : https://codeforces.com/contest/427/submission/153624061
