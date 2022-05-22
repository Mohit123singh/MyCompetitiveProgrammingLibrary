
#include <bits/stdc++.h>
using namespace std;

// Patter-Finding-Algo-KMP-O(N+M)

vector<int> build_lps(string s)
{
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


//Problem1 : https://codeforces.com/problemset/problem/126/B
//Solution : https://codeforces.com/contest/126/submission/158001055