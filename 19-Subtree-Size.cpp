#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;


const int N = 1e5 + 100;
vector<int>adj[N];
vector<bool>visted(N, false);
vector<int>subtree_size(N, 0);

int dfs(int node,int p=-1)
{
    int size = 1;
    for (auto child : adj[node])
    {
        if (child!=p)
            size += dfs(child);
    }
    subtree_size[node] = size;
    return size;
}

// Problem1 : https://cses.fi/problemset/task/1674
// Solution : https://cses.fi/paste/5874a0b2496e45593a91b3/
