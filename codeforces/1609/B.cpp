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
    int n, q, num = 0;
    cin >> n >> q;
    string s;
    cin >> s;
    REP(i, 2, n)
    {
        if (s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a')
        {
            num++;
            i += 2;
        }
    }
    REP(i, 0, q)
    {
        int ind;
        char c;
        cin >> ind >> c;
        ind--;
        if (s[ind] == c)
            cout << num << '\n';
        else
        {
            if (ind >= 2 && s[ind] == 'c' && s[ind - 1] == 'b' && s[ind - 2] == 'a')
                num--;
            else if (ind >= 1 && ind <= n - 2 && s[ind] == 'b' && s[ind - 1] == 'a' && s[ind + 1] == 'c')
                num--;
            else if (ind <= n - 3 && s[ind] == 'a' && s[ind + 1] == 'b' && s[ind + 2] == 'c')
                num--;

            s[ind] = c;
            if (ind >= 2 && s[ind] == 'c' && s[ind - 1] == 'b' && s[ind - 2] == 'a')
                num++;
            else if (ind >= 1 && ind <= n - 2 && s[ind] == 'b' && s[ind - 1] == 'a' && s[ind + 1] == 'c')
                num++;
            else if (ind <= n - 3 && s[ind] == 'a' && s[ind + 1] == 'b' && s[ind + 2] == 'c')
                num++;

            cout << num << '\n';
        }
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
        // cout.flush();
    }
}