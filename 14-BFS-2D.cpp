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
#define sta stack<type>
#define q1 queue<type>
#define stt unordered_set<type>
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
// BFS on 2d grid:::::

queue<pii> u;
const int N = 1e3;

bool visted[N][N];

int dist[N][N];

vi dx{-1, 0, 1, 0};
vi dy{0, 1, 0, -1};

bool isValid(int i, int j, int n, int m)
{
    if (i < 1 || i > n || j < 1 || j > m || visted[i][j])
        rr false;
    rr true;
}
void bfs(int srcx, int srcy, int n, int m)
{
    u.push({srcx, srcy});
    while (!u.empty())
    {
        visted[srcx][srcy] = true;
        pii x = u.front();
        u.pop();
        int currX = x.ff;
        int currY = x.ss;

        for (int i = 0; i < 4; i++)
        {

            int newX = currX + dx[i];
            int newY = currY + dy[i];

            if (isValid(newX, newY, n, m))
            {
                u.push({newX, newY});

                visted[newX][newY] = true;

                dist[newX][newY] = dist[currX][currY] + 1;
            }
        }
    }
    // distance array::
    foo(i, n)
    {
        foo(j, m)
                cout
            << dist[i][j] << " ";
        cout << endl;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    foo(i, n)
    {
        foo(j, m)
        {
            visted[i][j] = false;
            dist[i][j] = 0;
        }
    }
    bfs(1, 1, n, m);

    rr;
}

/*Practice-Problems
    https://www.codechef.com/problems/SNSOCIAL (MultiSource-BFS)
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