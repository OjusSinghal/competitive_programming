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

#define REP(i, a, b) for (int i = a; i < b; i++)
#define VECITR(itr, v) for (vit itr = v.begin(); itr != v.end(); itr++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sq(a) ((a) * (a))

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

void pushLazy(vi &lazy, vi &tree, int i)
{
    tree[2 * i + 1] += lazy[i];
    lazy[2 * i + 1] += lazy[i];
    tree[2 * i + 2] += lazy[i];
    lazy[2 * i + 2] += lazy[i];
    lazy[i] = 0;
}

void updateRange(vi &lazy, vi &tree, int lo, int hi, int l, int r, int i, int addend)
{
    if (r < lo || l > hi)
        return;
    if (l <= lo && r >= hi)
    {
        tree[i] += addend;
        lazy[i] += addend;
    }
    else
    {
        int mid = (lo + hi) / 2;
        if (lazy[i] != 0)
            pushLazy(lazy, tree, i);
        updateRange(lazy, tree, lo, mid, l, r, 2 * i + 1, addend);
        updateRange(lazy, tree, mid + 1, hi, l, r, 2 * i + 2, addend);
        tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
    }
}

int mini(vi &tree, int lo, int hi, int l, int r, int i)
{
    if (lo >= l && hi <= r)
        return tree[i];
    if (hi < l || lo > r)
        return INT32_MAX;
    int mid = (lo + hi) / 2;
    return min(mini(tree, lo, mid, l, r, 2 * i + 1), mini(tree, mid + 1, hi, l, r, 2 * i + 2));
}

void run()
{
    int n, m;
    cin >> n >> m;
    m *= 2;
    vector<pair<int, pii>> segs(n);
    REP(i, 0, n)
    {
        int l, r, w;
        cin >> l >> r >> w;
        l--;
        r--;
        segs[i].F = w;
        segs[i].S.F = 2 * l;
        segs[i].S.S = 2 * r;
    }
    sort(segs.begin(), segs.end());

    vi tree(4 * m), lazy(4 * m);
    int l = 0, r = -1;
    int answer = 1e7;
    while (l < n)
    {
        if (r < l)
        {
            r++;
            if (r >= n)
                break;
            updateRange(lazy, tree, 0, m - 2, segs[r].S.F, segs[r].S.S, 0, 1);
        }

        if (mini(tree, 0, m - 2, 0, m - 2, 0) > 0)
        {
            answer = min(answer, segs[r].F - segs[l].F);
            updateRange(lazy, tree, 0, m - 2, segs[l].S.F, segs[l].S.S, 0, -1);
            l++;
        }

        else
        {
            r++;
            if (r >= n)
                break;
            updateRange(lazy, tree, 0, m - 2, segs[r].S.F, segs[r].S.S, 0, 1);
        }
    }
    cout << answer << endl;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t = 1;
    // cin >> t;

    while (t--)
    {
        run();
        // cout.flush();
        // cout << endl;
    }
}