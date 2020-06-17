/***
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://maruftuhin.com
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        200010

// clang-format off
// clang-format on

#ifdef redback
#define debug(...) {cout << "Line " << __LINE__ << " => "; __f(#__VA_ARGS__, __VA_ARGS__);}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {os << "{"; for (auto it = v.begin(); it != v.end(); ++it) {if (it != v.begin()) os << ", "; os << *it;} return os << "}";}
template <typename T> ostream& operator<<(ostream& os, const set<T>& v) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if (it != v.begin()) os << ","; os << *it;} return os << "]";}
template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <typename T1, typename T2> ostream& operator<<(ostream& os, const map<T1, T2>& v) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if (it != v.begin()) os << ", "; os << it->first << " = " << it->second;} return os << "]";}
template <typename T> void __f(const char* name, T&& arg1) {cout << name << " = " << arg1 << std::endl;}
template <typename T, typename... Args> void __f(const char* names, T&& arg1, Args&&... args) {const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " = " << arg1 << " | "; __f(comma + 1, args...);}
template <typename T> void __f(const char* name, T a[], int n) {cout << name << " = ["; for (int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << "]" << endl;}
#else
#define debug(args...)
#endif

string ans;
ll     N, M;

vector<string> str(20);

ll sum;

bool check(string s) {
    ll sum = 0;

    for (ll j = 0; j < N; j++) {
        sum = 0;
        for (ll i = 0; i < M; i++) {
            if (s[i] != str[j][i]) {
                sum++;
            }
        }
        if (sum > 1) {
            return false;
        }
    }
    return true;
}

void solve(ll t) {
    ll i, j, k;
    ll n, m;
    cin >> n >> m;
    N = n;
    M = m;
    string tmp;
    for (i = 0; i < n; i++) {
        cin >> str[i];
    }

    debug(str, n, m);

    if (m == 1 || n == 1) {
        cout << str[0] << "\n";
        return;
    }

    for (i = 0; i < m; i++) {
        for (j = 'a'; j <= 'z'; j++) {
            string s = str[0];
            s[i]     = j;
            if (check(s)) {
                cout << s << "\n";
                return;
            }
        }
    }

    cout << "-1\n";

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
