#include <algorithm>
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
#include <numeric>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef vector<vector<int>> vii;

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

string largeModulo(const string &a, const string &b)
{
    return "";
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

int INF = int(1e9);

int rec(vii &dp, const vi &arr, const vi &start, const int i, const int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (arr[i - 1] == 0)
        dp[i][j] = min(rec(dp, arr, start, i - 1, j - 1) + abs(i - 1 - start[j - 1]),
                       rec(dp, arr, start, i - 1, j));
    else
        dp[i][j] = rec(dp, arr, start, i - 1, j);

    return dp[i][j];
}

void run()
{
    int n;
    cin >> n;
    vi arr(n), start;
    REP(i, 0, n)
    {
        cin >> arr[i];
        if (arr[i] == 1)
            start.PB(i);
    }

    vii dp(n + 1, vi(start.size() + 1, -1));
    REP(i, 0, start.size() + 1) { dp[0][i] = INF; }
    REP(i, 0, n + 1) { dp[i][0] = 0; }

    cout << rec(dp, arr, start, n, start.size()) << "\n";

}

int main()
{
    // cin.tie(NULL);
    // ios_base::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    REP(i, 0, t) { run(); }
}