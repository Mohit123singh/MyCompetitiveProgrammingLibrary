#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e6 + 100;
vector<int> adj[N];
vector<int> color(N, -1);

bool check_bipartiateGraph(int node, int col)
{
    color[node] = col;
    for (auto child : adj[node])
    {
        if (color[child] == -1)
        {
            if (!check_bipartiateGraph(child, col ^ 1))
                return false;
        }
        else if (color[node] == color[child])
            return false;
    }
    return true;
}

// Problem1 : https://codeforces.com/contest/1296/problem/E1
// Solution : https://codeforces.com/contest/1296/submission/153083555