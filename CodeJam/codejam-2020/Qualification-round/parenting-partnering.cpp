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

typedef long long   ll;
#define mem(a, b)   memset(a,b,sizeof(a))
#define inf         1e9
#define eps         1e-9
#define mod         1000000007
#define NN          100010


#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cout<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cout << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

struct node {
    int x;
    int y;
    int in;
    char user;
    
    node(){}

    node(int X, int Y, int IN){
        x=X;
        y=Y;
        in=IN;
    }
};

node arr[1010];

bool comp(node a, node b) {
    if (a.x == b.y) {
        return a.y < b.y;
    }
    return a.x < b.x;
}


int main() {
#ifdef redback
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    ll t = 1, tc;
    cin >> tc ;
    ll n, m;
    while ( tc--) {
        cin >> n;
        ll i,c, j, k;
        for (int i = 0; i < n; ++i) {
            cin>>j>>k;
            arr[i]=node(j,k,i);
        }

        sort(arr,arr+n,comp);
        c=-1,j=-1;
        ll flag=0;

        for (int i = 0; i < n; ++i) {
            // debug(arr[i].x, arr[i].y, c, j)
            if(arr[i].x>=c){
                arr[i].user='C';
                c=arr[i].y;
            } else if (arr[i].x>=j) {
                arr[i].user = 'J';
                j=arr[i].y;
            } else {
                flag=1;
                break;
            }
        }

        printf("Case #%d: ",t++);

        if (flag) {
           printf("IMPOSSIBLE\n");
           continue;
        }

        char ans[1010];

        for (int i = 0; i < n; ++i) {
            ans[arr[i].in]=arr[i].user;
        }
        ans[n]=0;

        printf("%s\n",ans );

    }
    return 0;
}
