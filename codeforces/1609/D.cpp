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

class disjointSetUnion
{
private:
    vi links, setSize;
    int n;

public:
    disjointSetUnion(int n)
    {
        this->links = vi(n);
        this->setSize = vi(n, 1);
        this->n = n;

        REP(i, 0, n) { links[i] = i; }
    }

    void merge(int u, int v)
    {
        int up = find(u), vp = find(v);
        if (up == vp)
            return;
        if (setSize[up] >= setSize[vp])
        {
            links[vp] = up;
            setSize[up] += setSize[vp];
        }
        else
        {
            links[up] = vp;
            setSize[vp] += setSize[up];
        }
    }

    int getSize(int u)
    {
        return setSize[find(u)];
    }

    bool same(int u, int v)
    {
        return find(u) == find(v);
    }

    // private:
    int find(int u)
    {
        return links[u] = (links[u] == u) ? u : find(links[u]);
    }
};

void run()
{
    int n, d;
    cin >> n >> d;
    disjointSetUnion dsu(n);
    int pending = 0;

    REP(query, 0, d)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (dsu.same(x, y))
            pending++;
        else
            dsu.merge(x, y);

        set<int> parents;
        REP(i, 0, n)
        parents.insert(dsu.find(i));
        vi cap;
        for (int i : parents)
            cap.PB(dsu.getSize(i));
        if (pending >= cap.size())
            cout << n - 1 << '\n';
        else
        {
            // cout << "HERE\n";
            ll sum = 0;
            sort(cap.rbegin(), cap.rend());

            // for (int i : parents) cout << i << ' ';
            // cout << endl;
            // for (int i : cap) cout << i << ' ';
            // cout << endl;
            // cout << pending << endl;

            REP(i, 0, pending + 1) { sum += cap[i]; }
            cout << sum - 1 << '\n';
        }
        // cout.flush();
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