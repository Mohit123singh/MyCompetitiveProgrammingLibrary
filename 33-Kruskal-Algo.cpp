

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

class edge
{
public:
    int u, v, w;
    edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
};

vector<edge> edges;

const int N = 1e6;
int par[N], s[N];

bool comp(edge &e1, edge &e2)
{
    return e2.w > e1.w;
}

void make(int node)
{
    par[node] = node;
    s[node] = 1;
}

int find(int node)
{
    if (node == par[node])
        return node;
    return par[node] = find(par[node]);
}

void UNION(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (s[b] > s[a])
            swap(a, b);
        par[b] = a;
        s[a] += s[b];
    }
}

int find_mst()
{
    sort(edges.begin(), edges.end(), comp);
    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        int a = it.u;
        int b = it.v;
        int weight = it.w;

        if (find(a) != find(b))
        {
            UNION(a, b);
            mst.push_back({a, b});
            cost += weight;
        }
    }
    cout << cost << endl;
    for (auto it : mst)
        cout << it.first << " " << it.second << endl;
}

// Problem1 : https://codeforces.com/contest/1245/problem/D
// Solution : https://codeforces.com/contest/1245/submission/153793311
