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
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
void run()
{
    int n, e;
    cin >> n >> e;
    vi a(n);
    REP(i, 0, n) { cin >> a[i]; }
    ll ans = 0;

    vi before(n), after(n);
    for (int i = e; i < n; i++)
    {
        if (a[i - e] == 1)
            before[i] = before[i - e] + 1;
    }
    for (int i = n - 1 - e; i >= 0; i--)
    {
        if (a[i + e] == 1)
            after[i] = after[i + e] + 1;
    }

    REP(i, 0, n)
    {
        if (isPrime(a[i]))
        {
            ans += after[i];
            ans += before[i];
            ans += 1LL * before[i] * after[i];
        }
    }

    cout << ans << '\n';
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