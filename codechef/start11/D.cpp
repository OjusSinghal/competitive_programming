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

const ll mod = 1e9 + 7;


void run()
{
    int n; cin >> n;
    n--;
    vector<ll> b(n);
    REP(i, 0, n) { cin >> b[i]; }
    ll ways = 1;

    if (n == 1) {
        cout << ll(2 * (1e5 - b[0]) + 1) % mod << "\n";
        return;
    }

    REP(i, 1, n - 1) {
        if (b[i] < b[i - 1] && b[i] < b[i + 1]) {
            cout << 0 << "\n";
            return;
        }
    }

    if (b[0] > b[1]) ways = (ways * (ll(2 * (1e5 - b[0]) + 1))) % mod;
    if (b[n - 1] > b[n - 2]) ways = (ways * (ll(2 * (1e5 - b[n - 1]) + 1))) % mod;

    REP(i, 1, n - 1) {
        if (b[i] > b[i - 1] && b[i] > b[i + 1])
            ways = (ways * (ll(2 * (1e5 - b[i]) + 1))) % mod;
    }

    REP(i, 0, n - 1) {
        int j = i + 1;

        while (j < n && b[j] == b[i]) j++;
        if (j == i + 1) continue;

        int ex = 0;

        if (i == 0) ex++;
        else if (b[i] > b[i - 1]) ex++;

        if (j == n) ex++;
        else if (b[j - 1] > b[j]) ex++;

        int l = j - i - 4 + 2 * ex;
        if (l < 1) continue;
        ll x = b[i];
        vector<ll> dp(l + 1);
        dp[0] = 100000 - x + 1;
        dp[1] = (2 * (100000 - x) + 1) % mod;
        REP(z, 2, l + 1) {
            dp[z] = (dp[z - 1] + dp[z - 2] * (100000 - x)) % mod;
        }

        // cout << "here into dp\n";
        // cout << "i: " << i << " j: " << j << " ex: " << ex << " l: " << l << " x: " << x << "\n";
        // cout << "dp: ";
        // for (int we : dp) cout << we << " ";
        // cout << endl;

        ways = (ways * dp[l]) % mod;
        i = j;
    }

    cout << ways << "\n";
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
        cout.flush();
    }
}