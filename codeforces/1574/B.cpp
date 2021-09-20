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
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int maxi = 0;
    maxi += max(0, a - 1);
    maxi += max(0, b - 1);
    maxi += max(0, c - 1);
    int mini = 0;
    mini = max(mini, a - 1 - (b + c));
    mini = max(mini, b - 1 - (a + c));
    mini = max(mini, c - 1 - (a + b));

    if (m > maxi || m < mini) cout << "no\n";
    else cout << "yes\n";
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