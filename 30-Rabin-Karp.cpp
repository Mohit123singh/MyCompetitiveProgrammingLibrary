

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define ff first
#define ss second
#define ll long long int
#define int long long int
#define type int
#define type1 int
#define type2 int
#define pb push_back
#define mp make_pair
#define pii pair<type, type>
#define vi vector<type>
#define fo(i, n) for (type i = 0; i < n; i++)
#define foo(i, n) for (type i = 1; i <= n; i++)
#define mi(x) map<type1, type2> x
#define mii(x) unordered_map<type1, type2> x
#define maxheap priority_queue<type>
#define minheap priority_queue<type, vi, greater<type>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define PI 3.14159265358979323846
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, typee) typee *arr = new typee[n];
#define test(x) \
    int x;      \
    cin >> x;   \
    while (x--)
//#define mt19937             rng(chrono::steady_clock::now().time_since_epoch().count());
#define endl "\n"
#define sz() size()
#define ct continue
#define br break
#define rr return
#define I(x) x.begin(), x.end()
#define G(x) x.rbegin(), x.rend()
#define acc accumulate

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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

const int N = 1e6;
vi dp(N), P(N);
void init(string s)
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
    rr hash;
}

int find_hash(int l, int r)
{
    int hash = dp[r];
    if (l)
        hash = (hash - dp[l - 1] + mod) % mod;
    rr hash;
}

void solve()
{
    int n;
    while (cin >> n)
    {
        string sub, s;
        cin >> sub >> s;

        init(s);

        int l = 0;
        int r = sub.sz() - 1;
        int n = s.sz();

        int hash_value = calculate_hash_substring(sub);
        int p = 31;
        while (r < n)
        {
            int res = (hash_value * P[l]) % mod;
            if (res == find_hash(l, r))
                cout << l << endl;
            l++;
            r++;
        }
        cout << endl;
    }

    rr;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //test(t)
    solve();

    return 0;
}
