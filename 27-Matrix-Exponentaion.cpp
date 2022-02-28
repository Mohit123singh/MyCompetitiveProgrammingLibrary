
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

const int N = 110;
int dp[N][N], I[N][N], res[N][N];
int n, m;

void multiply(int A[][N], int B[][N])
{

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int sum = 0;

            for (int k = 1; k <= m; k++)
                sum = (sum + (A[i][k] * B[k][j]) % mod) % mod;
            res[i][j] = sum;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
            A[i][j] = res[i][j];
    }
}
void matrixPow()
{
    foo(i, m)
    {
        foo(j, m)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

    while (n)
    {
        if (n % 2 == 0)
        {
            multiply(dp, dp);
            n /= 2;
        }
        else
        {
            multiply(I, dp);
            n--;
        }
    }
    foo(i, m)
    {
        foo(j, m) cout << I[i][j] << " ";
        cout << endl;
    }
}
void solve()
{
    cin >> m >> n;

    foo(i, m)
    {
        foo(j, m) cin >> dp[i][j];
    }
    matrixPow();
}

/*
    Practice-Problems:

    https://www.spoj.com/problems/MPOW/

    Solution:
    https://www.spoj.com/submit/MPOW/id=29190400



    https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem

    Solution:
    https://www.hackerrank.com/challenges/fibonacci-finding-easy/submissions/code/258479461



    

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
