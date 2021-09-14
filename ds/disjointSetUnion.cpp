// DISJOINT SET UNION

// OPERATIONS SUPPORTED:
//      -> CONSTRUCTOR (SIZE OF UNION OF ALL SETS) {O(N)}

//      -> ALL THE FOLLOWING ARE LOG(N):
//      -> MERGE (U, V) [MERGE SETS CONTAINING THESE TWO ELEMETS]
//      -> SIZE (U) [SIZE OF THE SET CONTAINING U]
//      -> SAME (U, V) [WHEATHER U, V BELONG TO THE SAME SET]

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

class disjointSetUnion {
private:
    vi links, setSize;
    int n;

public:
    disjointSetUnion(int n) {
        this->links = vi(n);
        this->setSize = vi(n, 1);
        this->n = n;

        REP(i, 0, n) { links[i] = i; }
    }

    void merge(int u, int v)
    {
        int up = find(u), vp = find(v);
        if (up == vp) return;
        if (setSize[up] >= setSize[vp]) {
            links[vp] = up;
            setSize[vp] += setSize[up];
        }
        else {
            links[up] = vp;
            setSize[up] += setSize[vp];
        }
    }

    int getSize(int u) {
        return setSize[find(u)];
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

private:
    int find(int u) {
        return links[u] = (links[u] == u) ? u : find(links[u]);
    }
};

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