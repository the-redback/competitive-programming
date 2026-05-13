#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct data {
    ll sum;
    ll xtra;
} tree[300010];

void update(int node, int low, int high, int qlow, int qhigh, int value) {
    // No overlap
    if (qhigh < low || qlow > high) return;

    // Complete overlap
    if (qlow <= low && high <= qhigh) {
        tree[node].sum += 1LL * (high - low + 1) * value;
        tree[node].xtra += value;
        return;
    }

    int left = node * 2;
    int right = left + 1;
    int mid = (low + high) / 2;

    update(left, low, mid, qlow, qhigh, value);
    update(right, mid + 1, high, qlow, qhigh, value);

    tree[node].sum =
        tree[left].sum + tree[right].sum + tree[node].xtra * (high - low + 1);
}

ll query(int node, int low, int high, int qlow, int qhigh, ll carry) {
    // No overlap
    if (qhigh < low || qlow > high) return 0;

    // Complete overlap
    if (qlow <= low && high <= qhigh) {
        return tree[node].sum + carry * (high - low + 1);
    }

    int left = node * 2;
    int right = left + 1;
    int mid = (low + high) / 2;

    carry += tree[node].xtra;
    ll p1 = query(left, low, mid, qlow, qhigh, carry);
    ll p2 = query(right, mid + 1, high, qlow, qhigh, carry);
    return p1 + p2;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc, t = 1;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        printf("Case %d:\n", t++);
        memset(tree, 0, sizeof(tree));
        while (q--) {
            int i, j, k, l;
            cin >> i;
            if (i == 0) {
                cin >> j >> k >> l;
                update(1, 1, n, j + 1, k + 1, l);
            } else if (i == 1) {
                cin >> j >> k;
                ll ans = query(1, 1, n, j + 1, k + 1, 0);
                printf("%lld\n", ans);
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
