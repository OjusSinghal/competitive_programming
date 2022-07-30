// BUILD TREE FROM INDIVIDUAL CALLS,
// UPDATES:
//      -> RANGE(ADD)
// QUERIES:
//      -> RANGE (MIN)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define VECITR(itr, v) for (vit itr = v.begin(); itr != v.end(); itr++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sq(a) ((a) * (a))

void pushLazy(vi &lazy, vi &tree, int i)
{
    tree[2 * i + 1] += lazy[i];
    lazy[2 * i + 1] += lazy[i];
    tree[2 * i + 2] += lazy[i];
    lazy[2 * i + 2] += lazy[i];
    lazy[i] = 0;
}

void updateRange(vi &lazy, vi &tree, int lo, int hi, int l, int r, int i, int addend)
{
    if (r < lo || l > hi) return;
    if (l <= lo && r >= hi) {
        tree[i] += addend;
        lazy[i] += addend;
    }
    else {
        int mid = (lo + hi) / 2;
        if (lazy[i] != 0) pushLazy(lazy, tree, i);
        updateRange(lazy, tree, lo, mid, l, r, 2 * i + 1, addend);
        updateRange(lazy, tree, mid + 1, hi, l, r, 2 * i + 2, addend);
        tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
    }
}

int mini(vi &lazy, vi &tree, int lo, int hi, int l, int r, int i)
{
    if (lo >= l && hi <= r) return tree[i];
    if (hi < l || lo > r) return INT32_MAX;
    pushLazy(lazy, tree, i);
    int mid = (lo + hi) / 2;
    return min(mini(lazy, tree, lo, mid, l, r, 2 * i + 1), mini(lazy, tree, mid + 1, hi, l, r, 2 * i + 2));
}

void run()
{
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t = 1;
    // cin >> t;

    while (t--)
        run();
}