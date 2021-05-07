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

int gcd(int a, int b)
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


int dfs(vector<vector<bool>> &change, vector<string> &arr, int i, int j, int k)
{
    return 0;
}


void run()
{
    int n; //, x; 
    cin >> n; // >> x;

    string s; cin >> s;

    vector<bool> arr(26);
    arr[s[0] - 'A'] = true;

    REP(i, 1, n)
    {
        if (s[i] == s[i - 1]) continue;
        if (arr[s[i] - 'A']) { cout << "NO\n"; return; }
        arr[s[i] - 'A'] = true;
    }

    cout << "YES\n";
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t = 1;
    cin >> t;

    REP(i, 0, t) { run(); }
}