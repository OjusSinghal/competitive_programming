#include <bits/stdc++.h>

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
#define MT make_tuple
#define F first
#define S second
#define sq(a) ((a) * (a))
#define v(t) vector<t>
#define all(v) v.begin(), v.end()

// O(log(min(a, b)))
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// avoids integer overflow
ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}

// optimized gcd
ll fast_gcd(ll a, ll b) {
    if (!a || !b) return a | b;
    unsigned shift = __builtin_ctzll(a | b);
    a >>= __builtin_ctzll(a);
    do {
        b >>= __builtin_ctzll(b);
        if (a > b) swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

// O(log(min(a, b)))
// extended euclidean
// solve for (x, y) in ax + by = gcd(a, b)
// returns gcd(a, b), also solves for (x, y)
ll extendedEuclidean(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        tie(x, y) = MT(1, 0);
        return a;
    }
    ll x1, y1;
    ll g = extendedEuclidean(b, a % b, x1, y1);
    tie(x, y) = MT(y1, x1 - (a / b) * y1);
    return g;
}

ll modulo(ll x, ll m) {
    ll r = x % m;
    return r < 0 ? r + m : r;
}

ll power(ll n, ll k) {
    if (k == 0) return 1LL;
    ll ans = 1;
    while (k > 0) {
        if (k & 1) ans *= n;
        n *= n;
        k /= 2;
    }
    return ans;
}

ll power(ll n, ll k, ll mod) {
    if (k == 0) return 1LL;
    n %= mod;
    ll ans = 1;
    while (k > 0) {
        if (k & 1) ans = (ans * n) % mod;
        n = (n * n) % mod;
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


// number of divisors of n
int numberOfDivisors(int n)
{
    int count = 1;
    vi arr;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            arr.PB(1);
            while (n % i == 0) {
                n /= i;
                arr.back()++;
            }
        }
        i++;
    }
    for (int x : arr) count *= x;
    if (n != 1) count *= 2;

    return count;
}

bool is_palindrome(const string &s)
{
    return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
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

// O(n)
// returns list of primes upto n (inclusive)
// 32 times more memory than lognSieve,
// worst time than lognSieve although better complexity
vector<int> linearSieve(int n)
{
    vi prime, lp(n + 1, 0);
    for (ll i = 2; i < n + 1; i++) {
        if (lp[i] == 0) {
            prime.PB(i);
            lp[i] = i;
        }

        for (int j = 0; j < prime.size() && i * prime[j] < n + 1 && prime[j] <= lp[i]; j++) {
            lp[i * prime[j]] = prime[j];
        }
    }
    return prime;
}

// O(n * log(log(n)))
// vector<bool> takes 1/32 times the memory of linearSieve, but is slower
// vector<char> takes 1/4 times the memory of linearSieve, but is fastest
// returns boolean array of all numbers, ar[i] = true -> i is composite
vector<char> lognSieve(int n) {
    vector<char> composite(n + 1);
    for (ll i = 2; i * i < n + 1; i++) {
        if (!composite[i]) {
            for (ll j = i * i; j <= n; j += i) composite[j] = true;
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


string next_valid_bracket_sequence(const string &x) {
    string s = x;
    int n = s.size();
    int d = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (s[i] == ')') d++;
        else {
            d--;
            if (d > 0) {
                s[i] = ')';
                s = s.substr(0, i + 1);
                REP(j, 0, (n - i - d) / 2) { s += "("; }
                REP(j, 0, (n - i + d - 2) / 2) { s += ")"; }
                if (s.size() < n) return s + ")";
                return s;
            }
        }
    }
    
    return "";
}


bool valid_bracket_sequence(const string &s) {
    int n = s.size();
    int b = 0;
    for (char c : s) {
        if (c == ')') b--;
        else b++;
        if (b < 0) return false;
    }
    return b == 0;
}

void run()
{
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t = 0;
    // cin >> t;

    while (t--)
    {
        run();
    }
}