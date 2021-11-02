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

void run()
{
    int n;
    cin >> n;
    v(ll) a(n);
    REP(i, 0, n) { cin >> a[i]; }
    sort(all(a));
    ll mini = a[0];
    ll del = -a[0];
    REP(i, 0, n - 1)
    {
        ll cur = a[i] + del;
        mini = max(mini, cur);
        del -= cur;
    }

    if (n > 1)
        mini = max(mini, a[n - 1] - a[n - 2]);

    cout << mini << '\n';
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
        // cout.flush();
    }
}