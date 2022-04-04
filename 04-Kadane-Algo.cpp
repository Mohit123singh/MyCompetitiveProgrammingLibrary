#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

// kadane's algo:
// Maximum sum in all sub-array of given array;

int kadane_Algo(vector<int> &a)
{

    int sum = 0;
    int ans = INT_MIN;

    for (auto it : a)
    {
        sum += it;
        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }
    return ans;
}

// Problem 1 :  https://codeforces.com/problemset/problem/327/A
// Solution  :  https://codeforces.com/contest/327/submission/146227273
