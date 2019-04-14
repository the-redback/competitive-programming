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
#define sf(a)        scanf("%d",&a)
#define ssf(a)       scanf("%s",a)
#define sf2(a, b)    scanf("%d %d",&a,&b)
#define sf3(a, b, c) scanf("%lld %lld %lld",&a,&b,&c)
#define inf          1e9
#define eps          1e-9
#define mod          1000000007


#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cout<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cout << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

#define NN 10000

bool p[NN + 7]; //Hashing
vector<int>pr; //storing prime
vector<int>ans;
vector<int>v;
set<int>pos;
map<int, int>mmp;

int N;

void sieve(int n) {
    int i, j, k, l;
    p[1] = 1;
    pr.push_back(2);
    for (i = 4; i <= n; i += 2)
        p[i] = 1;
    for (i = 3; i <= n; i += 2) {
        if (p[i] == 0) {
            pr.push_back(i);
            for (j = i * i; j <= n; j += 2 * i)
                p[j] = 1;
        }
    }
}

void factor(int n) {
    int k, i;
    for (i = 0; i < pr.size() && pr[i]*pr[i] <= n; i++) {
        k = pr[i];
        if (n % k == 0) {
            int j = n / k;
            pos.insert(k);
            pos.insert(j);
            v.pb(k);
            v.pb(j);
            break;
        }
    }
}

bool poss(void) {
    ans.clear();
    ans.pb(v[0]);

    for (int i = 1; i < v.size(); i += 2) {
        if (i + 2 >= v.size() )
            break;
        if (v[i] == v[i + 1]) {
            ans.pb(v[i]);
        } else if (v[i] == v[i + 2]) {
            ans.pb(v[i]);
            swap(v[i + 1], v[i + 2]);
        } else {
            // no answer
            return false;
        }
    }
    ans.pb(v[v.size()-1]);
    return true;
}

int main() {
#ifdef redback
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    sieve(NN);

    int t = 1, tc;
    sf(tc);
    int n, m;
    while (tc--) {
        ans.clear();
        v.clear();
        pos.clear();
        int i, j, k, l;
        sf2(n, l);
        N = n;
        for (i = 0; i < l; i++) {
            sf(k);
            factor(k);
        }

        i = 0;
        for (auto it = pos.begin(); it != pos.end(); it++, i++) {
            mmp[*it] = i;
        }

        if (!poss()) {
            swap(v[0], v[1]);
            poss();
        }

        printf("Case #%d: ", t++);



        for (i = 0; i < ans.size(); i++) {
            k = mmp[ans[i]];
            printf("%c", k + 'A');
        }
        printf("\n");

    }
    return 0;
}
