#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

// 0-1 BFS Algorithm:

const int N = 1e5 + 100;
bool visted[N];
vector<pair<int, int>> adj[N];
int dist[N];

void bfs_01(int node)
{
    dist[node] = 0;
    deque<int> dq;
    dq.push_front(0);
    while (!dq.empty())
    {
        int node = dq.front();
        dq.pop_front();

        for (auto child : adj[node])
        {
            if (dist[child.first] > dist[node] + child.second)
            {
                int w = child.second;
                dist[child.first] = dist[node] + child.second;
                if (w == 1)
                    dq.push_back(child.first);
                else
                    dq.push_front(child.first);
            }
        }
    }
}

// Problem 1 : https://www.codechef.com/problems/REVERSE
// Solution  : https://www.codechef.com/viewsolution/62691045

// Problem 2  : https://www.spoj.com/problems/KATHTHI/
// Solution   : https://ideone.com/Sp5vgy