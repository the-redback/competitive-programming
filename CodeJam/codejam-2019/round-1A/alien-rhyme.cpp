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

struct trie {
    bool endmark;
    int unressolve;
    int next[26];
    trie() {
        endmark = 0;
        for (ll i = 0; i < 26; i++)
            next[i] = -1;
    }
};

vector<trie>tree;

void Insert(string arr, int start) { ///Insert arr string
    ll node = 0;
    for (ll i = start; i < arr.size(); i++) {
        ll id = arr[i] - 'A';

        if (tree[node].next[id] == -1) {
            tree[node].next[id] = (int)tree.size();
            tree.pb(trie());
        }
        node = tree[node].next[id];
    }
    tree[node].endmark = 1; ///endmark marks the ending of a string
}

int rec(int node) {
    int sum = 0;

    if (tree[node].endmark == 1) {
        sum++;
    }

    for (int i = 0; i < 26; i++) {
        if (tree[node].next[i] != -1)
            sum += rec(tree[node].next[i]);
    }
    if (node != 0  && sum > 1)
        sum -= 2;
    return sum;
}

int main() {
#ifdef redback
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif

    char arr[100];
    string str;


    int t = 1, tc;
    sf(tc);
    int i, j, k, l, m, n;
    while (tc--) {
        tree.pb(trie());  ///Root node actually.

        sf(n);      ///No of word in dictionary.
        for (i = 0; i < n; i++) {
            scanf("%s", arr);
            str.assign(arr);
            Insert(string(str.rbegin(), str.rend()), 0);  ///Insert arr string into dictionary.
        }

        int sum = rec(0);
        printf("Case #%d: %d\n", t++, n - sum );

        tree.clear(); ///Delete The Memory.
    }
    return 0;
}
