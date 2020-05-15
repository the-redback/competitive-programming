/***
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://maruftuhin.com
 */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        200010

// clang-format off
#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cout<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cout << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros
// clang-format on

ll a[NN];
ll sum;
ll N;

vector<pair<ll, ll>> v;

void rec(ll l, ll r, ll in) {
    sum++;
    ll k;
    if (r < l) {
        return;
    }

    if (l == r) {
        k = l;
    } else if ((r - l + 1) % 2 == 1) {
        k = (l + r) / 2;
    } else {
        k = (l + r - 1) / 2;
    }
    v.push_back(make_pair(r - l + 1, k));
    rec(l, k - 1, in * 2);
    rec(k + 1, r, (in * 2) + 1);
    return;
}

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

void solve(ll tc) {
    ll i, j, k, n;
    cin >> n;

    v.clear();
    sum = 0;

    rec(1, n, 1);
    sort(v.begin(), v.end(), comp);
    for (i = 0; i < v.size(); i++) {
        a[v[i].second] = i + 1;
    }

    for (i = 1; i <= n; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1, tc;
    cin >> tc;
    ll n, m;
    while (tc--) {
        solve(t++);
    }
    return 0;
}
