#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

void create_prefix_array(vector<int> a, vector<int> &pre, int n)
{
    for (int i = 0; i < n; i++)
    {
        pre[i] = a[i];
        if (i)
        {
            pre[i] = pre[i] + pre[i - 1];
        }
    }
}

int get_sum_between_range(vector<int> pre, int l, int r)
{
    int sum = pre[r];
    if (l)
    {
        sum = sum - pre[l - 1];
    }
    return sum;
}

// Problem1 :  https://codeforces.com/problemset/problem/1355/C
// Solution : https://codeforces.com/contest/1355/submission/146055465

// Problem2 : https: // codeforces.com/contest/295/problem/A (prefix sum + scanline algo)
// Solution : https://codeforces.com/contest/296/submission/146061590
