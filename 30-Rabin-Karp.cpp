#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e6;
vector<int> dp(N), P(N);
void generate_hash_of_text(string s)
{
    int n = s.sz();
    int p = 31;
    P[0] = 1;
    for (int i = 1; i < n; i++)
        P[i] = (P[i - 1] * p) % mod;

    dp[0] = s[0] - 'a' + 1;

    for (int i = 1; i < n; i++)
        dp[i] = (dp[i - 1] + (s[i] - 'a' + 1) * P[i]) % mod;
}

int calculate_hash_substring(string sub)
{
    int P = 1, p = 31, hash = 0;
    for (auto it : sub)
    {
        hash = (hash + (it - 'a' + 1) * P) % mod;
        P = (P * p) % mod;
    }
    return hash;
}

int find_hash(int l, int r)
{
    int hash = dp[r];
    if (l)
        hash = (hash - dp[l - 1] + mod) % mod;
    rr hash;
}

void find_occurence(string s,string p)
{
    generate_hash_of_text(s);

    int hash_of_pattern=calculate_hash_substring(p);

    int l=0;
    int r=p.size()-1;

    while(r<s.size())
    {
      int res=(hash_of_pattern * P[l])%mod;

      if(res==find_hash(l,r))
      cout << l+1<<endl;
      l++;
      r++;
    }
}

// Problem 1 : https://www.spoj.com/problems/NAJPF/
// Solution  : https://ideone.com/e0l0dm