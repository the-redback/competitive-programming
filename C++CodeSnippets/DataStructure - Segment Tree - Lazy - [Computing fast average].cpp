#include <cstring>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

typedef long long ll;

#define NN 10010

struct Data {
    ll sum;
    ll xtra;
};

Data tree[300010];
ll a[NN];

void init(ll node, ll low, ll high) {
    tree[node].xtra = -1;

    if (low == high) {
        tree[node].sum = a[low];
        return;
    }
    ll left = node * 2;
    ll right = left + 1;
    ll mid = (low + high) / 2;

    init(left, low, mid);
    init(right, mid + 1, high);
    tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
    return;
}

void update(ll node, ll low, ll high, ll qlow, ll qhigh, ll value) {
    // No overlap
    if (qhigh < low || qlow > high) return;

    // Complete overlap
    if (qlow <= low && high <= qhigh) {
        tree[node].sum = (high - low + 1) * value;
        tree[node].xtra = value;
        return;
    }

    ll left = node * 2;
    ll right = left + 1;
    ll mid = (low + high) / 2;

    // Lazy propagation
    if (tree[node].xtra != -1) {
        tree[left].xtra = tree[node].xtra;
        tree[right].xtra = tree[node].xtra;

        tree[left].sum = (mid - low + 1) * tree[left].xtra;
        tree[right].sum = (high - mid) * tree[right].xtra;

        tree[node].xtra = -1;
    }

    update(left, low, mid, qlow, qhigh, value);
    update(right, mid + 1, high, qlow, qhigh, value);

    tree[node].sum = tree[left].sum + tree[right].sum;
}

ll query(ll node, ll low, ll high, ll qlow, ll qhigh, ll carry) {
    // No overlap
    if (qhigh < low || qlow > high) return 0;

    if (carry != -1) {
        return (min(high, qhigh) - max(low, qlow) + 1) * carry;
    }

    // Complete overlap
    if (qlow <= low && high <= qhigh) {
        return tree[node].sum;
    }

    ll left = node * 2;
    ll right = left + 1;
    ll mid = (low + high) / 2;

    if ((high - low + 1) * tree[node].xtra == tree[node].sum)
        carry = tree[node].xtra;

    ll p1 = query(left, low, mid, qlow, qhigh, carry);
    ll p2 = query(right, mid + 1, high, qlow, qhigh, carry);

    return p1 + p2;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll tc, t = 1;
    cin >> tc;
    while (tc--) {
        ll n, q;
        cin >> n >> q;
        cout << "Case " << t++ << ":" << "\n";

        memset(a, 0, sizeof(a));
        init(1, 1, n);
        while (q--) {
            ll i, j, k, l;
            cin >> i;

            if (i == 1) {
                cin >> j >> k >> l;
                update(1, 1, n, j + 1, k + 1, l);
            } else if (i == 2) {
                cin >> j >> k;
                ll ans = query(1, 1, n, j + 1, k + 1, -1);
                ll res = (k - j + 1);
                ll g = gcd(res, ans);

                if (res / g > 1)
                    cout << ans / g << "/" << res / g << "\n";
                else
                    cout << ans / g << "\n";
            }
        }
    }
    return 0;
}

// https://lightoj.com/problem/computing-fast-average
