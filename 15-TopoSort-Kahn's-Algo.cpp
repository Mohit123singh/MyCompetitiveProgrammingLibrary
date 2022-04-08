#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
vector<int> topo;
vector<int> indeg(N, 0);
queue<int> u;
bool kahnAlgo(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            u.push(i);
    }

    while (!u.empty())
    {
        int curr = u.front();
        u.pop();
        topo.push_back(curr);
        for (auto child : adj[curr])
        {
            indeg[child]--;
            if (indeg[child] == 0)
                u.push(child);
        }
    }
    // check cycle in a direct-graph using kahn-algo:
    if (topo.size() == n)
        return true;
    return false;
}