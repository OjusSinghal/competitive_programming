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
    int n, m, k;
    cin >> n >> m >> k;
    v(string) grid(n);
    REP(i, 0, n) { cin >> grid[i]; }
    vii ver(n, vi(m));

    REP(i, 0, n)
    {
        REP(j, 0, m)
        {
            if (grid[i][j] == '*')
            {
                bool tick = true;
                REP(z, 1, k + 1)
                {
                    if (i - z < 0 || j - z < 0 || j + z >= m)
                    {
                        tick = false;
                        break;
                    }
                    if (grid[i - z][j - z] != '*' || grid[i - z][j + z] != '*')
                    {
                        tick = false;
                        break;
                    }
                }
                if (tick)
                {
                    ver[i][j] = 1;
                    int z = 1;
                    while (true)
                    {
                        if (i - z < 0 || j - z < 0 || j + z >= m)
                        {
                            // tick = false;
                            break;
                        }
                        if (grid[i - z][j - z] == '*' && grid[i - z][j + z] == '*')
                        {
                            ver[i - z][j - z] = 1;
                            ver[i - z][j + z] = 1;
                        }
                        else
                            break;
                        z++;
                    }
                }
            }
        }
    }

    REP(i, 0, n)
    {
        REP(j, 0, m)
        {
            if (grid[i][j] == '*' && ver[i][j] == 0)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";

    // REP(i, 0, n) {REP(j, 0, m) {cout << ver[i][j] << " "; } cout << "\n"; }
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