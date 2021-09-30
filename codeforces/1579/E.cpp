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

// class Compare
// {
// public:
//     bool operator()(pii p1, pii p2)
//     {
//         return p1.F < p2.F;
//     }
// };

// bool cmp(pii p, pii pi)
// {
//     return p.F < pi.F;
// }

void run()
{
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    REP(i, 0, n)
    {
        int x;
        cin >> x;
        if (x > 0)
            pq.push(MP(x, i));
    }

    v(pii) ans(0);

    while (pq.size() > 1)
    {
        pii p1 = pq.top();
        pq.pop();
        pii p2 = pq.top();
        pq.pop();

        ans.PB({p1.S, p2.S});

        if (p1.F > 1)
            pq.push(MP(p1.F - 1, p1.S));

        if (p2.F > 1)
            pq.push(MP(p2.F - 1, p2.S));

        if (pq.size() < 2)
            break;
    }

    cout << ans.size() << "\n";
    REP(i, 0, ans.size())
    {
        cout << ans[i].F + 1 << " " << ans[i].S + 1 << "\n";
    }
    // cout << "\n";
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