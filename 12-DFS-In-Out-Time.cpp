#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e6 + 100;
vector<int> adj[N];
int timer;
int inTime[N], outTime[N];
bool visted[N];

void dfs(int node)
{
    visted[node] = true;
    inTime[node] = timer++;
    for (auto child : adj[node])
    {
        if (!visted[child])
            dfs(child);
    }
    outTime[node] = timer++;
}

// Problem1 : https://codeforces.com/contest/1006/problem/E
// Solution : https://codeforces.com/contest/1006/submission/153153886
