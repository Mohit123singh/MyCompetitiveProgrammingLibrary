#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

// Sliding-Window-Technique::

// Maximum-Sum of k-size-window  in an Array

int find_maximum_sum(vector<int> a, int k, int n)
{
    int sum = 0;

    // find the sum of first k elements:

    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    int max_value = sum;

    // find-maximum-sum in every window-size of k :
    // update the max_value;

    for (int i = k; i < n; i++)
    {
        sum += a[i];
        sum -= a[i - k];
        max_value = max(max_value, sum);
    }
    return max_value;
}

// Problem1 : https://codeforces.com/problemset/problem/363/B
// Solution : https://codeforces.com/contest/363/submission/146230482

// Problem2 : https://codeforces.com/problemset/problem/279/B
// Solution : https://codeforces.com/contest/279/submission/146233346

// Problem3 : https://codeforces.com/contest/1341/problem/B
// Solution : https://codeforces.com/contest/1341/submission/146238361
