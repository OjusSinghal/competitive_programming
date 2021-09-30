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
    vi a(n);
    REP(i, 0, n) { cin >> a[i]; }
    // int ans = 0;
    vector<tuple<int, int, int>> ans(0);
    REP(i, 0, n)
    {
        int mini = a[i];
        int minid = i;
        REP(j, i + 1, n)
        {
            if (a[j] < mini)
            {
                mini = a[j];
                minid = j;
            }
        }
        if (minid == i)
            continue;
        ans.PB({i + 1, minid + 1, minid - i});
        for (int j = minid; j >= i + 1; j--)
        {
            a[j] = a[j - 1];
        };
        // cout << "i: " << i << endl;
        // REP(i, 0, n) { cout << a[i] << " "; }
        // cout << endl;
    }

    cout << ans.size() << "\n";
    REP(i, 0, ans.size()) { cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << "\n"; }
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