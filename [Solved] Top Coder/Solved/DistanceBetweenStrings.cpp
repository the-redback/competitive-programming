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

typedef long long          ll;
typedef unsigned long long llu;

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
#define NN        30100

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

struct DistanceBetweenStrings
{
    int getDistance(string a, string b, string c)
    {
        int ret=0;
        int i,j,k,l;
        int aa[200],bb[200];
        mem(aa,0);
        mem(bb,0);

        for(i=0;i<a.size();i++)
        {
            char ch=tolower(a[i]);
            aa[ch]++;
        }
        for(i=0;i<b.size();i++)
        {
            char ch=tolower(b[i]);
            bb[ch]++;
        }

        for(i=0;i<c.size();i++)
        {
            char ch=tolower(c[i]);
            k=aa[ch];
            l=bb[ch];
            int temp=abs(k-l);
            ret+=temp*temp;
        }

        return ret;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "topcoder"; string Arg1 = "contest"; string Arg2 = "tcp"; int Arg3 = 2; verify_case(0, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "abcdef"; string Arg1 = "fedcba"; string Arg2 = "fed"; int Arg3 = 0; verify_case(1, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "aaaaa"; string Arg1 = "bbbbb"; string Arg2 = "a"; int Arg3 = 25; verify_case(2, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "aaAaB"; string Arg1 = "BbaAa"; string Arg2 = "ab"; int Arg3 = 2; verify_case(3, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; string Arg1 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"; string Arg2 = "ba"; int Arg3 = 5000; verify_case(4, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "ToPcOdEr"; string Arg1 = "tOpCoDeR"; string Arg2 = "wxyz"; int Arg3 = 0; verify_case(5, Arg3, getDistance(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DistanceBetweenStrings ___test;
    ___test.run_test(-1);
    int gbase;
    cin>>gbase; // erase this line if you are not using dev-cpp! :)
    return 0;
}
// END CUT HERE

