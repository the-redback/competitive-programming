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

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        100010

#define read(a)   scanf("%lld",&a)

string ss;

ll check(void)
{
    ll ret=0,sum=0;
    ll i;
    for(i=0;i<ss.size();i++)
    {
        if(ss[i]=='+')
            sum++;
        else
            sum--;
        if(sum<0)
            ret++;
    }
    return ret;
}

struct Drbalance{
int lesscng(string s, int k)
{
    int ret=0;
    ss=s;

    for(ll i=0;i<s.size();i++)
    {
        if(check()<=k)
            break;
        if(ss[i]=='-')
        {
            ss[i]='+';
            ret++;
            if(check()<=k)
                break;
        }
    }
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "---"; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "+-+-"; int Arg1 = 0; int Arg2 = 0; verify_case(1, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "-+-+---"; int Arg1 = 2; int Arg2 = 1; verify_case(2, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "-------++"; int Arg1 = 3; int Arg2 = 3; verify_case(3, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "-+--+--+--++++----+"; int Arg1 = 3; int Arg2 = 2; verify_case(4, Arg2, lesscng(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
Drbalance ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
