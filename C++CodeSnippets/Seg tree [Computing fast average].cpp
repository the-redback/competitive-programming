/**
 *    @author     : Maruf Tuhin
 *    @College    : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        100010

#define read(a) scanf("%lld", &a)

struct data {
    ll sum;
    ll xtra;
} tree[300010];

void init(ll node, ll low, ll high) {
    if (low == high) {
        tree[node].sum = 0;
        tree[node].xtra = -1;
        return;
    }
    ll left = node * 2;
    ll right = left + 1;
    ll mid = (low + high) / 2;

    init(left, low, mid);
    init(right, mid + 1, high);
    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].xtra = -1;
    return;
}

void update(ll node, ll low, ll high, ll rlow, ll rhigh, ll value) {
    if (low >= rlow && high <= rhigh) {
        tree[node].sum = (high - low + 1) * value;
        tree[node].xtra = value;
        return;
    }
    ll left = node * 2;
    ll right = left + 1;
    ll mid = (low + high) / 2;

    if (tree[node].xtra != -1) {
        tree[left].xtra = tree[node].xtra;
        tree[right].xtra = tree[node].xtra;
        tree[left].sum = (mid - low + 1) * tree[left].xtra;
        tree[right].sum = (high - mid) * tree[right].xtra;
        tree[node].xtra = -1;
    }

    if (rhigh <= mid)
        update(left, low, mid, rlow, rhigh, value);
    else if (rlow > mid)
        update(right, mid + 1, high, rlow, rhigh, value);
    else {
        update(left, low, mid, rlow, mid, value);
        update(right, mid + 1, high, mid + 1, rhigh, value);
    }
    tree[node].sum = tree[left].sum + tree[right].sum;
}

ll query(ll node, ll low, ll high, ll rlow, ll rhigh, ll carry) {
    if (carry != -1) {
        return (rhigh - rlow + 1) * carry;
    }

    if (low >= rlow && high <= rhigh) {
        return tree[node].sum;
    }

    ll left = node * 2;
    ll right = left + 1;
    ll mid = (low + high) / 2;

    ll p1 = 0, p2 = 0;
    if ((high - low + 1) * tree[node].xtra == tree[node].sum)
        carry = tree[node].xtra;
    if (rhigh <= mid)
        p1 = query(left, low, mid, rlow, rhigh, carry);
    else if (rlow > mid)
        p2 = query(right, mid + 1, high, rlow, rhigh, carry);
    else {
        p1 = query(left, low, mid, rlow, mid, carry);
        p2 = query(right, mid + 1, high, mid + 1, rhigh, carry);
    }
    return p1 + p2;
}

main() {
    ios_base::sync_with_stdio(false);
    ll tc, t = 1;
    cin >> tc;
    while (tc--) {
        ll n, q;
        cin >> n >> q;
        printf("Case %d:\n", t++);
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
                ll gcd = __gcd(res, ans);
                if (res / gcd > 1)
                    printf("%lld/%lld\n", ans / gcd, res / gcd);
                else
                    printf("%lld\n", ans / gcd);
            }
        }
    }
    return 0;
}
