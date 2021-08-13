// BUILD TREE FROM ARRAY, UPDATE SINGLE ENTRY, QUERY RANGE MINIMUM


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

#define REP(i, a, b) for (int i = a; i < b; i++)
#define VECITR(itr, v) for (vit itr = v.begin(); itr != v.end(); itr++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sq(a) ((a) * (a))

void build(const vi &arr, vi &tree, int lo, int hi, int i)
{
    if (hi == lo)
    {
        tree[i] = arr[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(arr, tree, lo, mid, (2 * i) + 1);
    build(arr, tree, mid + 1, hi, (2 * i) + 2);
    tree[i] = min(tree[(2 * i) + 2], tree[(2 * i) + 1]);
}

int mini(vi &tree, int lo, int hi, int l, int r, int i)
{
    if (lo >= l && hi <= r)
        return tree[i];
    if (hi < l || lo > r)
        return INT32_MAX;
    int mid = (lo + hi) / 2;
    return min(mini(tree, lo, mid, l, r, 2 * i + 1), mini(tree, mid + 1, hi, l, r, 2 * i + 2));
}

void update(vi &tree, int u, int val, int lo, int hi, int i)
{
    if (lo == hi)
    {
        tree[i] = val;
        return;
    }
    int mid = (lo + hi) / 2;
    if (u <= mid)
        update(tree, u, val, lo, mid, 2 * i + 1);
    else
        update(tree, u, val, mid + 1, hi, 2 * i + 2);
    tree[i] = min(tree[(2 * i) + 2], tree[(2 * i) + 1]);
}

void run()
{
    // vi a = {1, 3, -2, 8, -7};
    // vi tree(a.size() * 4);
    // build(a, tree, 0, a.size() - 1, 0);

    // for (int i : tree)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // update(tree, 2, 4, 0, a.size() - 1, 0);
    // for (int i : tree)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // update(tree, 0, -3, 0, a.size() - 1, 0);
    // for (int i : tree)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // update(tree, 4, 4, 0, a.size() - 1, 0);
    // for (int i : tree)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // REP(i, 0, a.size())
    // {
    //     REP(j, i, a.size())
    //     {
    //         cout << "minimum in the range(" << i << ", " << j << ") = " << mini(tree, 0, a.size() - 1, i, j, 0) << endl;
    //     }
    // }
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