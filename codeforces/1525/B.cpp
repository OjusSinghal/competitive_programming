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
                if (s.size() < n) return s + ")";
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
    if (k == 0) return 1LL;
    n %= mod;
    ll ans = 1;
    while(k > 0)
    {
        if (k & 1) ans = (ans * n) % mod;
        n = (n * n) % mod;
        k /= 2;
    }
    return ans;
}

ll power(ll n, ll k)
{
    if (k == 0) return 1LL;
    ll ans = 1;
    while(k > 0)
    {
        if (k & 1) ans *= n;
        n *= n; 
        k /= 2;
    }
    return ans;
}

void run()
{
    int n; cin >> n;
    vi arr(n);
    REP(i, 0, n) { cin >> arr[i]; }

    bool flag = true;
    REP(i, 0, n) { if (arr[i] != i + 1) { flag = false; break; }}

    if (flag) { cout << 0 << "\n"; return; }

    if (arr[0] == n && arr[n - 1] == 1) { cout << 3 << "\n"; return; }

    if (arr[0] == 1 || arr[n - 1] == n) { cout << 1 << "\n"; return; }

    cout << 2 << "\n";
    
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t = 1;
    cin >> t;
    REP(i, 0, t) { run();  cout.flush(); }
}