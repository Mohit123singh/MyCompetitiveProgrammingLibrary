
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
vi adj[N], level(N);
int dp[N][22];

void dfs(int node, int p = -1, int d = 0)
{
    dp[node][0] = p;
    level[node] = d;

    for (auto it : adj[node])
    {
        if (it == p)
            ct;
        dfs(it, node, d + 1);
    }
}
int find_LCA(int a, int b)
{
    if (level[a] > level[b])
        swap(a, b);
    int d = level[b] - level[a];
    while (d > 0)
    {
        int i = log2(d);
        b = dp[b][i];
        d -= ((int)1 << i);
    }
    if (a == b)
        rr a;

    for (int i = 20; i >= 0; i--)
    {
        if (dp[a][i] != -1 and dp[b][i] != -1 and dp[a][i] != dp[b][i])
        {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    rr dp[a][0];
}
void pre(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 20; j++)
            dp[i][j] = -1;
    }

    dfs(1);
    for (int i = 1; i <= 20; i++)
    {

        for (int node = 1; node <= n; node++)
        {
            int p = dp[node][i - 1];

            if (p != -1)
            {
                p = dp[p][i - 1];
                dp[node][i] = p;
            }
        }
    }
}
int find_distance(int a, int b)
{
    // formula:
    int ans = level[a] + level[b] - 2 * level[find_LCA(a, b)];
    rr ans;
}
void solve()
{

    int n, q;
    cin >> n >> q;
    foo(i, n) adj[i].clear(), level[i] = 0;
    for (int i = 2; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    pre(n);
    foo(l, q)
    {
        int x, y;
        cin >> x >> y;
        cout << find_distance(x, y) << endl;
    }

    rr;
}

/*Practice Problems:

    https://cses.fi/problemset/task/1135
*/

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //test(t)
    solve();

    return 0;
}
