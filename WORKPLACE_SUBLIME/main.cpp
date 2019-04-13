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
typedef unsigned long long llu;

#define ft           first
#define sd           second
#define mp           make_pair
#define pb(x)        push_back(x)
#define all(x)       x.begin(),x.end()
#define allr(x)      x.rbegin(),x.rend()
#define mem(a, b)    memset(a,b,sizeof(a))
#define sf(a)        scanf("%lld",&a)
#define ssf(a)       scanf("%s",a)
#define sf2(a, b)    scanf("%lld %lld",&a,&b)
#define sf3(a, b, c) scanf("%lld %lld %lld",&a,&b,&c)
#define inf          1e9
#define eps          1e-9
#define mod          1000000007
#define NN           100010


#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cout<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cout << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

string str[1001];
char tmp[101];
ll a[1001];
ll N;
vector< pair<string, string> >v;
ll fl;

ll rec(ll n) {
	if (n >= N) {
		//debug(">>>>>>>>>>>>>>>>>>>>>",n,v.size())
		map<string, int> mmp;
		for (int i = 0; i < v.size(); ++i) {
			string x = v[i].first;
			string y = v[i].second;
		//	debug(x,y)
			ll k = min(x.size() , y.size());
			while (k > 0) {
				string xx = x.substr(x.size()-k);
				string yy = y.substr(y.size()-k);
				if (xx == yy && mmp.find(xx) == mmp.end()) {
		//			debug("--------------------------",xx,yy)
					mmp[xx] = 1;
					break;
				}
				k--;
			}
			if (k == 0) {
				// no matching
				return 0;
			}

		}
		if (fl < v.size()*2) {
			fl = v.size()*2;
		}
		return v.size();
	}

	ll res = 0;

	for (int i = 0; i < N; i++) {
		if (a[i] == -1) {
			a[i] = 1;
			res = max(res, rec(n + 1));
			a[i] = -1;
		}
		for (int j = 0; j < N; j++) {
			if (a[i] == -1 && a[j] == -1 && i!=j) {
				a[i] = 1;
				a[j] = 1;
				v.pb(mp(str[i], str[j]));
				res = max(res, rec(n + 2));
				v.pop_back();
				a[i] = -1;
				a[j] = -1;
			}
		}
	}
	return res;
}

int main() {
#ifdef redback
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif

	ll t = 1, tc;
	sf(tc);
	ll n, m;
	while (tc--) {
		sf(n);
		v.clear();
		ll i, j, k;
		for ( i = 0; i < n; ++i) {
			scanf("%s", tmp);
			str[i] = tmp;
		}

		mem(a, -1);
		N = n;
		fl = 0;
		ll res = rec(0);
		printf("Case #%lld: %lld\n", t++, fl);

	}
	return 0;
}