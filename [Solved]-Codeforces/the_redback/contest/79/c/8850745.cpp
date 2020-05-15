#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>

using namespace std;

#include <ext/hash_set>
#include <ext/hash_map>

using namespace __gnu_cxx;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;

string str;
string strs[19];
int n;
int dp[100009];
int len;

int main() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "rt", stdin);
#endif
    cin >> str >> n;
    rep(i,n)
        cin >> strs[i];
    len = sz(str);
    int ind = n;
    for (int i = len - 1; i >= 0; i--) {
        string temp = str.substr(i, 1);
        if (dp[i + 1])
            temp += str.substr(i + 1, min(9, dp[i + 1]));
        int mn = oo;
        rep(j,n) {
            int i1 = 0, i2 = 0;
            while (i1 < sz(temp) && i2 < sz(strs[j])) {
                if (temp[i1] != strs[j][i2])
                    break;
                i1++;
                i2++;
            }
            if (i2 == sz(strs[j]))
                mn = min(mn, sz(strs[j]));
        }
        if (mn == oo)
            dp[i] = dp[i + 1] + 1;
        else
            dp[i] = mn - 1;
        if (dp[i] >= dp[ind])
            ind = i;
    }
    cout << dp[ind] << " " << ind << endl;
    return 0;
}