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
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cerr << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

ll a[50][50];
ll ar[500];
ll R, C, N;

bool rec(ll r, ll c, ll n) {
	if (n == N) {
		return true;
	}
	if (r == R || c == C) {
		return false;
	}

	if  (R < C ) {
		for (ll x = 0; x < R; x++) {
			for (ll y = 0; y < C; y++) {
				int i = (r + x) % R;
				int j = (c + y) % C;
				if ((a[i][j] == -1 && i != r && j != c && i - j != r - c && i + j != r + c)) {
					a[i][j] = n + 1;
					if ( rec(i, j, n + 1) ) {
						return true;
					}
					a[i][j] = -1;
				}
			}
		}

	} else {
		for (ll y = 0; y < C; y++) {
			for (ll x = 0; x < R; x++) {
				int i = (r + x) % R;
				int j = (c + y) % C;
				if ((a[i][j] == -1 && i != r && j != c && i - j != r - c && i + j != r + c) ) {
					a[i][j] = n + 1;
					if ( rec(i, j, n + 1) ) {
						return true;
					}
					a[i][j] = -1;
				}
			}
		}

	}
	return false;
}

int main() {
#ifdef redback
	freopen("input.in", "r", stdin);
//	freopen("output.in", "w", stdout);
#endif

	ll t = 1, tc;
	sf(tc);
	ll n, m;
	while (tc--) {
		ll i, j, k;
		sf2(n, m);
		R = n;
		C = m;
		N = n * m;
		mem(a, -1);
		printf("Case #%lld: ", t++);
		ll fl = 0;

		bool res;

		for (i = 0; i < C; ++i) {
			a[0][i]=1;
			res = rec(0, i, 1);
			debug(res)
			if (res) {
				break;
			}
			a[0][i]=-1;
		}
		if (res == false) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("POSSIBLE\n");
		fl = 1;
		for (k = 1; k <= N; k++) {
			for (i = 0; i < R; i++) {
				for (j = 0; j < C; j++) {
					if (a[i][j] == k) {
						printf("%lld %lld\n", i + 1, j + 1);
					}
				}
			}
		}

	}
	return 0;
}