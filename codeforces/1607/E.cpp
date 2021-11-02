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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int minih = 0, maxih = 0;
    int minib = 0, maxib = 0;
    int curh = 0, curb = 0;
    REP(i, 0, s.length())
    {
        if (s[i] == 'L')
            curb--;
        else if (s[i] == 'R')
            curb++;
        else if (s[i] == 'U')
            curh--;
        else
            curh++;

        if (abs(max(maxih, curh) - min(minih, curh)) >= n || abs(max(maxib, curb) - min(minib, curb)) >= m)
        {
            // cout << "i: " << i << endl;
            // cout << minih << ' ' << maxih << ' ' << minib << ' ' << maxib << endl;
            // if (minih < 0)
            cout << (1 - minih) << ' ';
            // else
            // cout << n << ' ';
            // if (minib < 0)
            cout << 1 - minib << '\n';
            // else
            // cout << m << '\n';
            return;
        }

        minih = min(minih, curh);
        maxih = max(maxih, curh);
        minib = min(minib, curb);
        maxib = max(maxib, curb);

        // if (abs(maxib - minib) >= m) {
        //     return;
        // }
    }

    // cout << minih << ' ' << maxih << ' ' << minib << ' ' << maxib << endl;
    // if (minih < 0)
    cout << (1 - minih) << ' ';
    // else
    // cout << n << ' ';

    // if (minib < 0)
    cout << 1 - minib << '\n';
    // else
    //     cout << m << '\n';
    // cout << "end\n";
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