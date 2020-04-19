/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long            ll;
typedef unsigned long long   llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define meminf(a) memset(a,126,sizeof(a))
#define inf       1e11
#define eps       1e-9
#define mod       1000000007
#define NN        60

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;
struct D
{
    ll x,y,c;
}a[NN];

ll N;
ll V,G;
ll dp[NN];

ll rec(ll pos)
{
    ll &tc=dp[pos];
    if(tc!=-1)
        return tc;
    ll i,j,k;
    ll mx=0;
    for(i=0;i<N;i++)
    {
        if(i==pos)
            continue;
        ll dy=a[pos].y-a[i].y;
        ll dx=abs(a[pos].x-a[i].x);
        if(dy<0)
            continue;
        ll t1=2*V*V*dy;
        ll t2=dx*dx*G;
        if(t1>=t2)
            mx=max(mx,rec(i)+a[i].c);
    }
    return tc=mx;
}

struct PlatformJumper
{
    int maxCoins(vector <string> plat, int v, int g)
    {
        ll ret,i;
        for(i=0;i<plat.size();i++)
        {
            int xx,yy,cc;
            sscanf(plat[i].c_str(),"%d %d %d",&xx,&yy,&cc);
            a[i].x=xx,a[i].y=yy,a[i].c=cc;
        }
        V=v;
        G=g;
        N=plat.size();
        mem(dp,-1);
        ret=0;
        for(i=0;i<plat.size();i++)
            ret=max(ret,rec(i)+a[i].c);

        return ret;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 5000 10", "1024 1156 1" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 99; int Arg2 = 72; int Arg3 = 11; verify_case(0, Arg3, maxCoins(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0 0 1", "2 4 1", "4 0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; verify_case(1, Arg3, maxCoins(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"0 0 1", "5000 5000 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 87; int Arg3 = 10; verify_case(2, Arg3, maxCoins(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PlatformJumper ___test;
    ___test.run_test(-1);
    int gbase;
    cin>>gbase; // erase this line if you are not using dev-cpp! :)
    return 0;
}
// END CUT HERE

