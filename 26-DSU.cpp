#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e6;
int par[N], s[N];

void make(int node)
{
    par[node] = node;
}

// Path-compression-technique:
int find(int node)
{
    if (node == par[node])
        return node;
    return par[node] = find(par[node]);
}

// union-by-size:
void Union(int a, int b)
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

// Problem1 : https://codeforces.com/contest/1534/problem/C
// Solution : https://codeforces.com/contest/1534/submission/154065417

// Problem2 : https://codeforces.com/contest/1332/problem/C
// Solution : https://codeforces.com/contest/1332/submission/154068605
