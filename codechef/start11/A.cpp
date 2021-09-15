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

void run()
{
    ll n, s; cin >> n >> s;
    ll ans = ((n * (n + 1)) / 2) - s;
    if (ans > 0 and ans <= n) cout << ans;
    else cout << -1;
    cout << endl;
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