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

vector<string> split(string input)
{
    vector<string> ret;
    istringstream ss(input);
    string token;

    while(std::getline(ss, token, ',')) {
        ret.push_back(token);
    }
    return ret;

}

vector<string>v;

char a[1000010];

ll num(string s)
{
    ll num=0;
    for(int i=0;i<s.size();i++)
        num=num*10+(s[i]-'0');

//    debug(num);
    return num;
}

vector<string>ans[400000];
ll pos,Mx=0;
void rec(ll dep)
{
    if(pos+1>=v.size())
        return;
    string str=v[pos];

    ll k=num(v[pos+1]);
    ans[dep].pb(str);
    pos+=2;
    Mx=max(Mx,dep);

    for(ll i=0;i<k;i++)
    {
        rec(dep+1);
    }
    return;

}

int main()
{
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //sf(tc);
    ll l,m,n;
    while(~ssf(a)) {
        ll i,j,k;
        v=split(a);
        pos=0;
        Mx=0;
        while(pos<v.size())
            rec(0);
        rec(0);

        printf("%lld\n",Mx+1);

        for(i=0;i<=Mx;i++)
        {
            for(j=0;j<ans[i].size();j++)
            {
                if(j!=0) printf(" ");
                printf("%s",ans[i][j].c_str());
            }
            printf("\n");
        }

        for(i=0;i<=Mx;i++)
            ans[i].clear();
        v.clear();


    }
    return 0;
}
