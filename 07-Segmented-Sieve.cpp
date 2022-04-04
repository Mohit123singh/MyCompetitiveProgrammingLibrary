#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

const int N = 1e6 + 100;
vector<int> primes;
vector<bool> isPrime(N, true);

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }
}

void generate_primes_in_range(int l, int r)
{
    if (l == 1)
        l++;
    int n = r - l + 1;
    vector<int> primes_in_range(n, 0);
    for (auto it : primes)
    {
        if (it * it <= r)
        {
            int x = (l / it) * it;

            if (x < l)
                x += it;

            for (; x <= r; x += it)
            {
                if (x != it)
                    primes_in_range[x - l] = 1;
            }
        }
        else
            break;
    }
    for (int i = 0; i < n; i++)
    {
        if (primes_in_range[i] == 0)
            cout << l + i << " ";
    }
}

// Problem 1 : https://www.spoj.com/problems/PRIME1/
// Solution :  https://ideone.com/P8A36U