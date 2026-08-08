#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;

#define NN 100010

struct Data {
    ll sum;
    ll lazy;  // pending addition
};

Data tree[4 * NN];

void push(ll node, ll low, ll high) {
    if (tree[node].lazy == 0 || low == high) return;

    ll mid = (low + high) / 2;
    ll left = node * 2;
    ll right = left + 1;

    tree[left].lazy += tree[node].lazy;
    tree[right].lazy += tree[node].lazy;

    tree[left].sum += (mid - low + 1) * tree[node].lazy;
    tree[right].sum += (high - mid) * tree[node].lazy;

    tree[node].lazy = 0;
}

void update(ll node, ll low, ll high, ll qlow, ll qhigh, ll value) {
    // No overlap
    if (qhigh < low || qlow > high) return;

    // Complete overlap
    if (qlow <= low && high <= qhigh) {
        tree[node].sum += (high - low + 1) * value;
        tree[node].lazy += value;
        return;
    }

    push(node, low, high);

    ll mid = (low + high) / 2;
    ll left = node * 2;
    ll right = left + 1;

    update(left, low, mid, qlow, qhigh, value);
    update(right, mid + 1, high, qlow, qhigh, value);

    tree[node].sum = tree[left].sum + tree[right].sum;
}

ll query(ll node, ll low, ll high, ll qlow, ll qhigh) {
    // No overlap
    if (qhigh < low || qlow > high) return 0;

    // Complete overlap
    if (qlow <= low && high <= qhigh) return tree[node].sum;

    push(node, low, high);

    ll mid = (low + high) / 2;
    ll left = node * 2;
    ll right = left + 1;

    return query(left, low, mid, qlow, qhigh) + query(right, mid + 1, high, qlow, qhigh);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc, t = 1;
    cin >> tc;

    while (tc--) {
        int n, q;
        cin >> n >> q;

        cout << "Case " << t++ << ":\n";

        memset(tree, 0, sizeof(tree));

        while (q--) {
            int i, j, k, l, r, val;
            cin >> i;
            if (i == 0) {
                cin >> l >> r >> val;

                update(1, 1, n, l + 1, r + 1, val);
            } else if (i == 1) {
                cin >> l >> r;

                ll ans = query(1, 1, n, l + 1, r + 1);
                cout << ans << "\n";
            }
        }
    }
    return 0;
}

/*
Problem: https://lightoj.com/problem/horrible-queries
Input:
2
10 5
0 0 9 10
1 1 6
0 3 7 2
0 4 5 1
1 5 5
20 3
0 10 12 1
1 11 12
1 19 19

Output:
Case 1:
60
13
Case 2:
2
0
*/
