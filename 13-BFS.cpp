#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

// BFS::

const int N = 1e5;
vector<int> adj[N];
bool visted[N];
int dist[N];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visted[node] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto child : adj[curr])
        {
            if (!visted[child])
            {
                visted[child] = true;
                q.push(child);
                dist[child] = dist[curr] + 1;
            }
        }
    }
}

// Problem 1 : https://codeforces.com/contest/796/problem/D
// Solution  : https://codeforces.com/contest/796/submission/153275938
