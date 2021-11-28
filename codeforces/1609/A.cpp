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
#include <climits>

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
    ll maxsum = 0;

    REP(j, 0, n)
    {
        v(ll) temp(n);
        REP(i, 0, n) { temp[i] = a[i]; }
        REP(i, 0, n)
        {
            if (i == j)
                continue;
            while ((temp[i] % 2) == 0 && temp[i] > 0)
            {
                temp[i] /= 2;
                temp[j] *= 2;
            }
        }
        ll sum = 0;
        REP(i, 0, n) { sum += temp[i]; }
        maxsum = max(maxsum, sum);
    }

    cout << maxsum << '\n';
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