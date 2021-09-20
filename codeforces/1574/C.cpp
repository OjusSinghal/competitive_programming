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
typedef vector<ll> vl;
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

void run()
{
    int n, m;
    cin >> n;
    vl her(n);
    ll sum = 0;
    REP(i, 0, n)
    {
        cin >> her[i];
        sum += her[i];
    }
    cin >> m;
    // cout << "M: " << m << endl;

    sort(all(her));

    REP(i, 0, m)
    {
        // cout << "ITERATE\n";
        ll def, at;
        cin >> def >> at;
        auto low = lower_bound(her.begin(), her.end(), def);
        if (low == her.end())
        {
            ll ans = def - her[n - 1] + max(0LL, at - (sum - her[n - 1]));
            cout << max(0LL, ans) << "\n";
            continue;
        }
        if (low == her.begin())
        {
            cout << max(0LL, at - (sum - her[0])) << "\n";
            continue;
        }
        ll ans = 1e18 + 10LL;
        ans = min(ans, at - (sum - (*low)));
        ll po = *(low - 1);
        ans = min(ans, def - po + max(0LL, at - (sum - po)));
        cout << max(0LL, ans) << "\n";
    }
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
        cout.flush();
    }
}