// // //
// Kind of inefficient (not the implementation, 2D segtrees in general)
// workd by splitting the 2d segment
// horizontally / vertically (whichever is suitable)
// lox, loy <= hix, hiy
// main function TLEs in the CSES problem Forests 2
// // //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPP(i, a, b) for (int i = a; i >= b; i--)
#define VECITR(itr, v) for (vit itr = v.begin(); itr != v.end(); itr++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sq(a) ((a) * (a))
#define v(t) vector<t>
#define all(v) v.begin(), v.end()

v(string) grid;
vi tree;

void build(int i, int loy, int lox, int hiy, int hix)
{
    if (loy == hiy && lox == hix)
    {
        tree[i] = (grid[loy][lox] == '*') ? 1 : 0;
        return;
    }
    int midx = (lox + hix) / 2;
    int midy = (loy + hiy) / 2;
    if (hix - lox >= hiy - loy)
    {
        // vertical division
        build(2 * i + 1, loy, lox, hiy, midx);
        build(2 * i + 2, loy, midx + 1, hiy, hix);
    }
    else
    {
        // horizontal division
        build(2 * i + 1, loy, lox, midy, hix);
        build(2 * i + 2, midy + 1, lox, hiy, hix);
    }
    tree[i] = tree[(2 * i + 1)] + tree[(2 * i + 2)];
}

void update(int i, int loy, int lox, int hiy, int hix, int ky, int kx)
{
    if (loy == hiy && lox == hix)
    {
        tree[i] = 1 - tree[i];
        return;
    }
    int midx = (hix + lox) / 2;
    int midy = (hiy + loy) / 2;

    if (hix - lox >= hiy - loy)
    {
        if (kx <= midx)
            update(2 * i + 1, loy, lox, hiy, midx, ky, kx);
        else
            update(2 * i + 2, loy, midx + 1, hiy, hix, ky, kx);
    }
    else
    {
        if (ky <= midy)
            update(2 * i + 1, loy, lox, midy, hix, ky, kx);
        else
            update(2 * i + 2, midy + 1, lox, hiy, hix, ky, kx);
    }
    tree[i] = tree[(2 * i + 1)] + tree[(2 * i + 2)];
}

int summ(int i, int loy, int lox, int hiy, int hix, int kloy, int klox, int khiy, int khix)
{
    if (kloy > hiy || klox > hix || khix < lox || khiy < loy)
        return 0;
    if (klox <= lox && kloy <= loy && khix >= hix && khiy >= hiy)
        return tree[i];
    int midx = (hix + lox) / 2;
    int midy = (hiy + loy) / 2;
    int fc, sc;
    if (hix - lox >= hiy - loy)
    {
        fc = summ(2 * i + 1, loy, lox, hiy, midx, kloy, klox, khiy, khix);
        sc = summ(2 * i + 2, loy, midx + 1, hiy, hix, kloy, klox, khiy, khix);
    }
    else
    {
        fc = summ(2 * i + 1, loy, lox, midy, hix, kloy, klox, khiy, khix);
        sc = summ(2 * i + 2, midy + 1, lox, hiy, hix, kloy, klox, khiy, khix);
    }
    return fc + sc;
}

void run()
{
    int n, q;
    cin >> n >> q;
    grid = v(string)(n);
    tree = vi(4 * sq(n));
    REP(i, 0, n) { cin >> grid[i]; }
    build(0, 0, 0, n - 1, n - 1);
    REP(i, 0, q)
    {
        int quer;
        cin >> quer;
        if (quer == 1)
        {
            int y, x;
            cin >> y >> x;
            y--, x--;
            update(0, 0, 0, n - 1, n - 1, y, x);
        }
        else
        {
            int kloy, klox, khiy, khix;
            cin >> kloy >> klox >> khiy >> khix;
            cout << summ(0, 0, 0, n - 1, n - 1, kloy - 1, klox - 1, khiy - 1, khix - 1) << '\n';
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