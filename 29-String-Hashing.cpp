
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int N = 1e6;
vector<int> dp(N), inv(N);

int power(int x, int y, int m = mod)
{
	int res = 1;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % m;
		x = (x * x) % m;
		y = y >> 1;
	}
	return res;
}

void generate_hash_text(string s)
{
    dp[0] = s[0] - 'a' + 1;
    inv[0] = 1;
    int p = 31;
    int P = 1;

    for (int i = 1; i < s.sz(); i++)
    {
        P = (P * p) % mod;
        dp[i] = (dp[i - 1] + (s[i] - 'a' + 1) * P) % mod;
        inv[i] = power(P, mod - 2);
    }
}

int calculate_hash(int l, int r)
{
    int hash = dp[r];
    if (l > 0)
        hash -= dp[l - 1];
    hash = (hash * inv[l]) % mod;
    return hash;
}

int generate_hash_pattern(string p)
{
   int hash=0;
   int p=31;
   int P=1;

   for(auto it:p)
   {
       hash=(hash + (it-'a'+1)*P)%mod;
       P=(P*p)%mod;
   }
   return hash;
}

int find_occurence(string s,string p)
{
    generate_hash_text(s);

    int l=0;

    int r=p.size()

    int hash_of_substring=generate_hash_pattern(p);

    while(r<s.size())
    {
        if(calculate_hash(l,r)==hash_of_substring)
            cout << l+1 << endl;
        l++;
        r++;
    }
}


// Problem1 : https://codeforces.com/problemset/problem/271/D
// Solution : https://codeforces.com/contest/271/submission/158135979