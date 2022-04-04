#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

// Sieve of Erasthones:used to generate all prime numbers upto n in O(Nlog(logN)).
// Auxiliiary space is O(n).....

const int N = 1e6 + 100;
vector<int> primes(N);
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

// Problem1 : https://www.codechef.com/problems/CDQU1
// Solution : https://www.codechef.com/viewsolution/61782102
