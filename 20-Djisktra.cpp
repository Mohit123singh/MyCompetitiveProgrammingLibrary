#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e5 + 100;
vector<pair<int, int>> adj[N];
vector<int> dist(N, 0);
vector<bool> visted(N, false);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

void dijkstra(int src)
{
    dist[src] = 0;
    p.push({0, src});
    while (!p.empty())
    {
        int curr_d = p.top().first;
        int node = p.top().second;
        p.pop();

        // if that node is visted,it means we have already assign smallest possible distance to that node
        //  it also shows that cycle is present.
        if (visted[node])
            continue;
        visted[node] = true;

        for (auto child : adj[node])
        {
            if (dist[child.first] > dist[node] + child.second)
            {
                dist[child.first] = dist[node] + child.second;

                p.push({dist[child.first], child.first});
            }
        }
    }
}

// Problem1 : https://codeforces.com/problemset/problem/20/C
// Solution : https://codeforces.com/contest/20/submission/153324349

// Problem2 : https://codeforces.com/contest/229/problem/B
// Solution : https://codeforces.com/contest/229/submission/153359435
