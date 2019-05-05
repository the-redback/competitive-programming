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
#define debug(args...) {cerr<<":: "; dbg,args; cerr<<endl;}
struct  debugger {template<typename T>debugger& operator , (const T& v) {cerr << v << " "; return *this;}} dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

vector<char> v{'A', 'B', 'C', 'D', 'E'};
vector<char>res;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef redback
    //freopen("input.in", "r", stdin);
    // freopen("output.in", "w", stdout);
     ofstream myfile ("example.txt");
#endif

    for (int i = 0; i < 5; ++i) {
        res.push_back(v[i]);
    }

    while (next_permutation(v.begin(), v.end())) {
        for (int i = 0; i < 5; ++i) {
            res.push_back(v[i]);
        }
    }

    ll t = 1, tc;
    cin >> tc ;
    ll n, m = 120;
    while (tc-- ) {
        ll i, j, k;

        cin >> n;

        char a, b, c, d, e;

        int low = 1;
        int high = 119;

        while (low < high) {
            ll mid = (low + high) / 2;
            ll rn = mid * 5;
             myfile <<"...........>>"<< rn<<"\n";
            n--;
            cout << rn - 4 << "\n";
            cout.flush();
            cin >> a;
            if ( a == 'N')
                return 0;

            n--;
            cout << rn - 3 << "\n";
            cout.flush();
            cin >> b;
            if ( b == 'N')
                return 0;

            n--;
            cout << rn - 2  << "\n";
            cout.flush();
            cin >> c;
            if ( c == 'N')
                return 0;

            n--;
            cout << rn - 1  << "\n";
            cout.flush();
            cin >> d;
            if ( d == 'N')
                return 0;

            n--;
            cout << rn << "\n";
            cout.flush();
            cin >> e;
            if ( e == 'N')
                return 0;

            // 0 based index
        myfile <<"...........--"<< a<<b<<c<<d<<e<<"\n";
            if (res[rn - 5] == a && res[rn - 4] == b && res[rn - 3] == c && res[rn - 2] == d && res[rn - 1] == e ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        while (n > 0) {
            cout << "1\n";
            cout.flush();
            cin >> e;
            if ( e == 'N')
                return 0;
            n--;
        }

        ll rn=low*5;
         myfile <<"\n-----------------" <<rn;


        string str;
        str+=res[rn - 5];
        str+=res[rn - 4];
        str+=res[rn - 3];
        str+=res[rn - 2];
        str+=res[rn - 1];

        cout << str << "\n";
        cout.flush();
        cin >> a;
        if (a != 'Y')
            break;

    }
    return 0;
}
