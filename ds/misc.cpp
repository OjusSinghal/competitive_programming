#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
#include <utility>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define VECITR(itr, v) for (vit itr = v.begin(); itr != v.end(); itr++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sq(a) ((a) * (a))
#define v(t) vector<t>
#define all(v) v.begin(), v.end()

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

string next_valid_bracket_sequence(const string &x)
{
    string s = x;
    int n = s.size();
    int d = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (s[i] == ')')
            d++;
        else
        {
            d--;
            if (d > 0)
            {
                s[i] = ')';
                s = s.substr(0, i + 1);
                REP(j, 0, (n - i - d) / 2) { s += "("; }
                REP(j, 0, (n - i + d - 2) / 2) { s += ")"; }
                if (s.size() < n)
                    return s + ")";
                return s;
            }
        }
    }

    return "";
}

ll modulo(ll x, ll m)
{
    int r = x % m;
    return r < 0 ? r + m : r;
}

ll power(ll n, ll k, ll mod)
{
    if (k == 0)
        return 1LL;
    n %= mod;
    ll ans = 1;
    while (k > 0)
    {
        if (k & 1)
            ans = (ans * n) % mod;
        n = (n * n) % mod;
        k /= 2;
    }
    return ans;
}

ll power(ll n, ll k)
{
    if (k == 0)
        return 1LL;
    ll ans = 1;
    while (k > 0)
    {
        if (k & 1)
            ans *= n;
        n *= n;
        k /= 2;
    }
    return ans;
}

ll inverse(ll n, ll mod) {
	return power(n, mod - 2, mod);
}

ll moduloDivide(ll a, ll b, ll mod) {
	ll temp = (inverse(a, mod) * b) % mod;
	return inverse(temp, mod);
}

int number_of_divisors(int n)
{
    int count = 1;
    vi arr;
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            arr.PB(1);
            while (n % i == 0)
            {
                n /= i;
                arr.back()++;
            }
        }
        i++;
    }
    for (int x : arr)
        count *= x;
    if (n != 1)
        count *= 2;

    return count;
}

bool isPalindrome(const string &s)
{
    int n = s.size();
    REP(i, 0, n / 2)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

ll nchoosek(ll n, ll k, ll mod)
{
    ll res = 1;
    for (ll i = 2; i <= k; i++)
        res = (res * i) % mod;

    res = power(res, mod - 2, mod) % mod;
    for (ll i = n; i >= n - k + 1; i--)
        res = (res * i) % mod;

    return res;
}

class allPerms
{
public:
    vector<vector<ll>> perm;
    int n;
    int mod = -1;

    allPerms(int n, int mod = -1)
    {
        this->mod = mod;
        this->n = n + 1;
        this->perm = vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0));
        set();
    }

    void set()
    {
        REP(i, 0, n) { perm[i][0] = 1; }
        // REP(i, 0, m) { perm[i][i] = 1; }

        if (mod > -1)
        {
            REP(i, 0, n - 1)
            {
                REP(j, 0, i + 1)
                {
                    if (j > 0)
                        perm[i + 1][j] = (perm[i + 1][j] + perm[i][j]) % mod;
                    perm[i + 1][j + 1] = (perm[i + 1][j + 1] + perm[i][j]) % mod;
                }
            }
        }
        else
        {
            REP(i, 0, n - 1)
            {
                REP(j, 0, i + 1)
                {
                    if (j > 0)
                        perm[i + 1][j] += perm[i][j];
                    perm[i + 1][j + 1] += perm[i][j];
                }
            }
        }
    }

public:
    ll get(int i, int j) { return perm[i][j]; }
};

// returns list of primes upto n (inclusive)
// 32 times more memory than lognSieve
vector<int> linearSieve(int n)
{
    vi prime, lp(n + 1, 0);
    for (ll i = 2; i < n + 1; i++)
    {
        if (lp[i] == 0)
        {
            prime.PB(i);
            lp[i] = i;
        }

        for (int j = 0; j < prime.size() && i * prime[j] < n + 1 && prime[j] <= lp[i]; j++)
        {
            lp[i * prime[j]] = prime[j];
        }
    }
    return prime;
}

// vector<bool> takes 1/32 times the memory of vector<int>
// returns boolean array of all numbers, ar[i] = true -> i is composite
vector<bool> lognSieve(int n) {
    vector<bool> composite(n + 1);
    for (ll i = 2; i * i < n + 1; i++)
    {
        if (!composite[i])
        {
            for (ll j = i * i; j <= n; j += i)
                composite[j] = true;
        }
    }

    return composite;
}

// pair.first = quotient
// pair.second = number of times this quotient appears
vector<pair<int, int>> allQuotients(int n)
{
    v(pii) Q;
    for (int i = 2; i <= n; i = (n / (n / i)) + 1)
        Q.PB({n / i, (n / (n / i)) - i + 1});
    return Q;
}

void run()
{
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;

    while (t--)
    {
        run();
    }
}