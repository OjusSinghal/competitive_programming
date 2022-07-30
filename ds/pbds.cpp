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

// find_by_order, order_of_key
// first "int" is the type of data
// ignore null_type 
// less<int> is comparator [use less_equal<int> for multiset]
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define VECITR(itr, v) for (vit itr = v.begin(); itr != v.end(); itr++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sq(a) ((a) * (a))
#define v(t) vector<t>
#define all(v) v.begin(), v.end()

// // //
// To erase from multiset defined by using the comparator less_equal<int>,
// do -> pb.erase(pb.find_by_order(pb.order_of_key(val)));
// // //

void run()
{
    pbds A; // declaration

    // Inserting elements - 1st query
    A.insert(1);
    A.insert(10);
    A.insert(2);
    A.insert(7);
    A.insert(2); // ordered set only contains unique values

    // A contains
    cout << "A = ";
    for (auto i : A)
        cout << i << " ";
    cout << endl;
    cout << endl;

    // finding kth element - 4th query
    cout << "0th element: " << *A.find_by_order(0) << endl;
    cout << "1st element: " << *A.find_by_order(1) << endl;
    cout << "2nd element: " << *A.find_by_order(2) << endl;
    cout << "3rd element: " << *A.find_by_order(3) << endl;
    cout << endl;

    // finding number of elements smaller than X - 3rd query
    cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl;   // 2
    cout << "No. of elems smaller than 11: " << A.order_of_key(11) << endl; // 4
    cout << "No. of elems smaller than 1: " << A.order_of_key(1) << endl;   // 0
    cout << endl;

    // lower bound -> Lower Bound of X = first element >= X in the set
    cout << "Lower Bound of 6: " << *A.lower_bound(6) << endl;
    cout << "Lower Bound of 2: " << *A.lower_bound(2) << endl;
    cout << endl;

    // Upper bound -> Upper Bound of X = first element > X in the set
    cout << "Upper Bound of 6: " << *A.upper_bound(6) << endl;
    cout << "Upper Bound of 1: " << *A.upper_bound(1) << endl;
    cout << endl;

    // // Remove elements - 2nd query
    A.erase(1);
    A.erase(11); // element that is not present is not affected

    // A contains
    cout << "A = ";
    for (auto i : A) cout << i << " ";
    cout << endl;
    
    // size of A
    cout << A.size() << endl;
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
    // cin >> t;

    while (t--)
    {
        run();
        // cout.flush();
    }
}