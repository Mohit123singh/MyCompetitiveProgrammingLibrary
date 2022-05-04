#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> BIT(N);
int n, q;

int find_right_most_set_bit(int p)
{
    return (p & ~(p - 1));
}

// O(logn)-> update: operation :

void update(int index, int val)
{
    while (index <= n)
    {
        BIT[index] += val;
        index += find_right_most_set_bit(index);
    }
}

// O(logn)-> find_sum : operation:

int find_sum(int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += BIT[index];
        index -= find_right_most_set_bit(index);
    }
    return sum;
}

// O(logn) -> lower_bound on prefix-sum : operation :

int lower_bound_prefix_sum(int v)
{
    int sum = 0, curr = 0;
    for (int i = log2(n); i >= 0; i--)
    {
        int j = ((int)1 << i);

        if (curr + j <= n and sum + BIT[curr + j] < v)
        {
            curr += j;
            sum += BIT[curr];
        }
    }
    return curr + 1;
}

// Problem1 : https://codeforces.com/contest/1354/problem/D
// Solution : https://codeforces.com/contest/1354/submission/155739640

// Problem2 : https://www.spoj.com/problems/INVCNT/
// Solution : https://ideone.com/qGoHaZ

// Problem3: