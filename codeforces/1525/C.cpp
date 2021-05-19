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
#include <numeric>
#include <vector>

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

struct robo
{
    int x, d;
};

void clean(vi &st, vi &ans, const vector<robo> &arr, const int m)
{
    while (st.size() > 1)
    {
        int i = st.back();
        st.pop_back();
        int j = st.back();
        if (arr[i].d == arr[j].d)
        {
            if (arr[i].d == 1)
            {
                ans[i] = ans[j] = m - ((arr[i].x + arr[j].x) / 2);
                st.pop_back();
            }
            else if (st.size() & 1)
            {
                ans[i] = ans[j] = (arr[i].x + arr[j].x) / 2;
                st.pop_back();
            }
        }
        else if (st.size() & 1)
        {
            st.pop_back();
            ans[i] = ans[j] = m + ((arr[j].x - arr[i].x) / 2);
        }
    }
    return;
}

void run()
{
    int n, m;
    cin >> n >> m;
    vector<robo> arr(n);
    REP(i, 0, n) { cin >> arr[i].x; }
    REP(i, 0, n)
    {
        char c;
        cin >> c;
        arr[i].d = c == 'L' ? -1 : 1;
    }

    vi a(n, 0);
    iota(a.begin(), a.end(), 0);
    sort(a.begin(), a.end(), [&arr](int i, int j)
         { return arr[i].x < arr[j].x; });

    vi ans(n, -1);
    vi oddStack, evenStack;

    for (int i : a)
    {
        vi *st;
        arr[i].x & 1 ? st = &oddStack : st = &evenStack;
        if (!st->size())
            st->PB(i);
        else
        {
            int j = st->back();
            if (arr[j].d == 1 && arr[i].d == -1)
            {
                ans[i] = ans[j] = (arr[i].x - arr[j].x) / 2;
                st->pop_back();
            }
            else
                st->PB(i);
        }
    }

    clean(oddStack, ans, arr, m);
    clean(evenStack, ans, arr, m);

    for (int i : ans)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t = 1;
    cin >> t;
    REP(i, 0, t) { run(); }
}