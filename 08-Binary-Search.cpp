
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

int find_lower_bound(vector<int> a, int n, int x)
{
    int l = 0;
    int h = n - 1;
    while (h - l > 1)
    {
        int mid = l + (h - l) / 2;

        if (a[mid] < x)
            l = mid + 1;
        else
            h = mid;
    }
    if (a[l] >= x)
        return l;
    else if (a[h] >= x)
        return h;
    return -1;
}

int find_upper_bound(vector<int> a, int n, int x)
{
    int l = 0;
    int h = n - 1;
    while (h - l > 1)
    {
        int mid = l + (h - l) / 2;

        if (a[mid] <= x)
            l = mid + 1;
        else
            h = mid;
    }
    if (a[l] > x)
        return l;
    else if (a[h] > x)
        return h;
    return -1;
}

// Problem 1 : https://codeforces.com/contest/75/problem/C
// Solution : https://codeforces.com/contest/75/submission/152560843

// Problem 2: https://codeforces.com/contest/778/problem/A
// Solution : https://codeforces.com/contest/778/submission/152567755

// Problem 3: https://codeforces.com/contest/1370/problem/D
// Solution : https://codeforces.com/contest/1370/submission/152586591
