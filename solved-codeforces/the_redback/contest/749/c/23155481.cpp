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

typedef long long          ll;
typedef unsigned long long llu;

#define ft         first
#define sd         second
#define mp         make_pair
#define pb(x)      push_back(x)
#define all(x)     x.begin(),x.end()
#define allr(x)    x.rbegin(),x.rend()
#define mem(a,b)   memset(a,b,sizeof(a))
#define sf(a)      scanf("%lld",&a)
#define ssf(a)     scanf("%s",&a)
#define sf2(a,b)   scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define inf        1e9
#define eps        1e-9
#define mod        1000000007
#define NN         100010

#ifdef  redback
#define bug printf("line=%d\n",__LINE__);
#define debug(args...) {cout<<":: "; dbg,args; cerr<<endl;}
struct  debugger{template<typename T>debugger& operator ,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#else
#define bug
#define debug(args...)
#endif  //debugging macros

struct node
{
    int w;
    node(){}
    node(int b) {w = b;}
    bool operator < ( const node& p ) const { return w > p.w; }
};

priority_queue<node>R,D;
char a[200010];
ll b[200010];

int main()
{
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //sf(tc);
    ll l,m,n;
    while(~sf(n)) {
        ll i,j,k;
        R=priority_queue<node>();
        D=priority_queue<node>();
        mem(b,-1);
        ssf(a);

        for(i=0;i<n;i++)
        {
            if(a[i]=='D') D.push(node(i));
            if(a[i]=='R') R.push(node(i));
        }

        while(!R.empty() && !D.empty())
        {
            node rr=R.top();
            node dd=D.top();
            R.pop();
            D.pop();

            if(rr.w<dd.w)
            {
                R.push(node(rr.w+n));
            }
            else
                D.push(node(dd.w+n));
        }

        if(!R.empty()) puts("R");
        else puts("D");

    }
    return 0;
}
