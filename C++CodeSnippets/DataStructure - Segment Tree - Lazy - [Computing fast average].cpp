#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>

using namespace std;

typedef long long ll;

#define NN 100010

struct Data {
    ll sum;
    ll lazy;  // pending assignment (-1 means no pending update)
};

Data tree[4 * NN];
ll a[NN];

void init(ll node, ll low, ll high) {
    tree[node].lazy = -1;

    if (low == high) {
        tree[node].sum = a[low];
        return;
    }
    ll mid = (low + high) / 2;
    ll left = node * 2;
    ll right = left + 1;

    init(left, low, mid);
    init(right, mid + 1, high);

    tree[node].sum = tree[left].sum + tree[right].sum;
}

void push(ll node, ll low, ll high) {
    if (tree[node].lazy == -1 || low == high) return;

    ll mid = (low + high) / 2;
    ll left = node * 2;
    ll right = left + 1;

    tree[left].lazy = tree[node].lazy;
    tree[right].lazy = tree[node].lazy;

    tree[left].sum = (mid - low + 1) * tree[node].lazy;
    tree[right].sum = (high - mid) * tree[node].lazy;

    tree[node].lazy = -1;
}

void update(ll node, ll low, ll high, ll qlow, ll qhigh, ll value) {
    // No overlap
    if (qhigh < low || qlow > high) {
        return;
    }

    // Complete overlap
    if (qlow <= low && high <= qhigh) {
        tree[node].sum = (high - low + 1) * value;
        tree[node].lazy = value;
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
    if (qhigh < low || qlow > high) {
        return 0;
    }

    // Complete overlap
    if (qlow <= low && high <= qhigh) {
        return tree[node].sum;
    }

    push(node, low, high);

    ll mid = (low + high) / 2;
    ll left = node * 2;
    ll right = left + 1;

    ll p1 = query(left, low, mid, qlow, qhigh);
    ll p2 = query(right, mid + 1, high, qlow, qhigh);

    return p1 + p2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tc, t = 1;
    cin >> tc;

    while (tc--) {
        ll n, q;
        cin >> n >> q;

        cout << "Case " << t++ << ":\n";

        memset(a, 0, sizeof(a));
        init(1, 1, n);

        while (q--) {
            ll i, l, r, val;
            cin >> i;

            if (i == 1) {
                cin >> l >> r >> val;

                update(1, 1, n, l + 1, r + 1, val);
            } else if (i == 2) {
                cin >> l >> r;

                ll sum = query(1, 1, n, l + 1, r + 1);
                ll len = r - l + 1;
                ll g = gcd(sum, len);

                if (len / g == 1)
                    cout << sum / g << '\n';
                else
                    cout << sum / g << "/" << len / g << '\n';
            }
        }
    }
    return 0;
}

// https://lightoj.com/problem/computing-fast-average
