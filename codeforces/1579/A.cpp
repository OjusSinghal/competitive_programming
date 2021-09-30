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
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    REP(i, 0, s.size())
    {
        if (s[i] == 'A')
            a++;
        else if (s[i] == 'B')
            b++;
        else
            c++;
    }
    if ((s.size() % 2) == 1)
    {
        cout << "NO\n";
        return;
    }
    // cout << a << " " << b << ' ' << c << "\n";

    if (b == (s.size() / 2))
    {
        cout << "YES\n";
        return;
    }
    // cout << "HERE";
    cout << "NO\n";
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