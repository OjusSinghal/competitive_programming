#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPP(i, a, b) for (int i = a; i >= b; i--)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define sq(a) ((a) * (a))
#define v(t) vector<t>
#define all(v) v.begin(), v.end()

#define duration(a) std::chrono::duration_cast<std::chrono::milliseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

void run()
{
    
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("temp/input.txt", "r", stdin);
    freopen("temp/output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) run();
}