// 32 BIT INTEGERS AS BINARY STRINGS
// BUILD TRIE FROM INDIVIDUAL CALLS,
// UPDATES:
//      -> ADD AN INTEGER TO THE TREE
//      -> REMOVE AN INTEGER FROM THE TREE
// QUERIES:
//      -> MAXIMUM XOR FOR A GIVEN INTEGER

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

struct node
{
    node *left;
    node *right;
    int val; //size of subtree, including this node

    node(int val)
    {
        this->left = nullptr;
        this->right = nullptr;
        this->val = val;
    }
};

void insert(node *u, string &b)
{
    node *cur = u;
    REP(i, 0, 32)
    {
        cur->val++;
        if (b[i] == '0')
        {
            if (cur->left == nullptr)
                cur->left = new node(0);
            cur = cur->left;
        }
        else
        {
            if (cur->right == nullptr)
                cur->right = new node(0);
            cur = cur->right;
        }
    }
    cur->val++;
}

void remove(node *u, string &b)
{
    node *cur = u;
    REP(i, 0, 32)
    {
        cur->val--;
        if (b[i] == '0')
        {
            if (cur->left->val == 1)
            {
                cur->left = nullptr;
                return;
            }
            cur = cur->left;
        }
        else
        {
            if (cur->right->val == 1)
            {
                cur->right = nullptr;
                return;
            }
            cur = cur->right;
        }
    }
    cur->val--;
}

int maxor(node *u, string &b)
{
    string ans = "";
    node *cur = u;
    REP(i, 0, 32)
    {
        if (b[i] == '1')
        {
            if (cur->left)
            {
                cur = cur->left;
                ans += "1";
            }
            else
            {
                cur = cur->right;
                ans += "0";
            }
        }
        else
        {
            if (cur->right)
            {
                cur = cur->right;
                ans += "1";
            }
            else
            {
                cur = cur->left;
                ans += "0";
            }
        }
    }
    return stoi(ans, 0, 2);
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